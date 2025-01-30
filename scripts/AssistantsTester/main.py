import json
import subprocess
import shutil
import os
import time
import sys
import concurrent.futures

import utils

CURRENT_RUN = 1  # 0 - working with problems, 1 - working with techniques

msbuild = r'D:\Program Files\Microsoft Visual Studio\2022\Community\MSBuild\Current\Bin\MSBuild.exe'
project_location = r'D:\facultate\re\ConsoleApplication5\ConsoleApplication5'
cmd = [msbuild, 'ConsoleApplication5.vcxproj', '/p:Configuration=Debug', '/p:PlatformTarget=x86']
console_executable = r'D:\facultate\re\ConsoleApplication5\ConsoleApplication5\Debug\ConsoleApplication5.exe'
console_vcxproj = r'D:\facultate\re\ConsoleApplication5\ConsoleApplication5\ConsoleApplication5.vcxproj'

# gview_location = r'D:\repos\GViewVersions\multiple\V1\GView.exe'
# gview_ini_location = r'D:\repos\GViewVersions\multiple\V1\gview.ini'
gview_instances_location_template = r'D:\repos\GViewVersions\multiple\V{}\GView.exe'
gview_instances_location = r'D:\repos\GViewVersions\multiple\V{}'

gview_location = r'D:\repos\GView\bin\Debug\GView.exe'
gview_ini_location = r'D:\repos\GView\bin\Debug\gview.ini'
gview_ini_tests = r'D:\repos\GView\bin\Debug\gview.ini.tests'

if CURRENT_RUN == 0:
    problems_location = r'D:\repos\AssistantsTester\problems'
    binaries_out = r'D:\repos\AssistantsTester\binaries\problems\\'
    gview_script_location = r'D:\repos\AssistantsTester\scripts\runNameQuery.gview'
    assistants_out = r'D:\repos\AssistantsTester\assistants\\'
    problems_input_location = r'D:\repos\AssistantsTester\assistants\problems.data'
    assistants_pattern = '????????????? Name selector ??????????????'
elif CURRENT_RUN == 1:
    problems_location = r'D:\repos\AssistantsTesterGithub\MiTRE\sources\all_sources'
    binaries_out = r'D:\repos\AssistantsTester\binaries\techniques\\'
    gview_check_run_script_location = r'gviewRunScripts/checkScript.gview'
    gview_run_script_location_template = r'gviewRunScripts/runScript.template'
    assistants_out = r'D:\repos\AssistantsTesterGithub\MiTRE\assistants_results\\'
    problems_input_location = ''
    assistants_pattern = '?????????? MITRE techniques ??????????'
else:
    print('Invalid run type')
    exit(1)
errors = []

modified_ini = False

thread_count = 10


def replicate_gview():
    gview_folder = os.path.dirname(gview_location)
    for index in range(1, thread_count + 1):
        current_gview_folder = gview_instances_location.format(index)
        if os.path.exists(current_gview_folder):
            shutil.rmtree(current_gview_folder)
        shutil.copytree(gview_folder, current_gview_folder)
        init_out = os.path.join(current_gview_folder, 'gview.ini')
        shutil.copy(gview_ini_tests, init_out)
    print(f'Replicated {thread_count} GView instanced in {gview_instances_location}')


def distribute_tasks(tasks):
    thread_tasks = {thread_id: [] for thread_id in range(1, thread_count + 1)}
    for index, task in enumerate(tasks):
        thread_id = (index % thread_count) + 1
        thread_tasks[thread_id].append(task)

    return thread_tasks


def process_thread(thread_id, tasks):
    program_location = gview_instances_location_template.format(thread_id)
    for file_location, output_location in tasks:
        output = run_gview(program_location, file_location)
        with open(output_location, 'w') as f:
            f.write(output)


def obtain_executable(source_name, just_name):
    out_location = binaries_out + just_name
    if os.path.exists(out_location):
        # print('Already exists binary: ' + just_name)
        return

    src_to_replace = r'D:\facultate\re\ConsoleApplication5\ConsoleApplication5\ConsoleApplication5.cpp'
    print('Processing: ' + just_name)
    with open(source_name, 'r') as f:
        with open(src_to_replace, 'w') as f2:
            f2.write(f.read())

    proc = subprocess.Popen(cmd, cwd=project_location)
    proc.communicate()

    try:
        shutil.move(console_executable, out_location)
    except:
        global errors
        errors.append(source_name)
        print('Failed to move file: ' + source_name)


def collect_binaries():
    for file in os.listdir(problems_location):
        file_location = os.path.join(problems_location, file)
        if not file.endswith('.cpp'):
            continue
        if '_NO' in file:
            print('Skipping source: ' + file)
            continue
        if os.path.isfile(file_location):
            # print('Processing: ' + file)
            utils.update_project_file(console_vcxproj, file_location)
            obtain_executable(file_location, os.path.splitext(file)[0])
    if len(errors) > 0:
        if len(errors) >= 2:
            print('\nFailed files: \n' + '\n'.join(errors))
        else:
            print('\nFailed file: \n' + errors[0])
    print('Finished collecting binaries')


def run_gview(gview_location_param, executable):
    # global modified_ini
    # if not modified_ini:
    #     modified_ini = utils.modify_ini(gview_ini_location, modified_ini)
    print('Processing: {}'.format(os.path.basename(executable)))
    command_list = [gview_location_param, 'test', executable, gview_check_run_script_location]
    command = ' '.join(command_list)
    result = subprocess.run(command, shell=True, stdout=subprocess.PIPE)
    out_result = result.stdout.decode('utf-8')

    lines_difference = 0
    found_current_line = False
    found_entry_point = False
    found_jmp = False
    out_result_lines = out_result.split('\r')
    for line in out_result_lines:
        if found_current_line:
            lines_difference += 1
        elif '-->' in line:
            found_current_line = True
        if found_entry_point:
            if 'jmp' in line:
                found_jmp = True
                break
        elif 'EntryPoint' in line:
            found_entry_point = True
    if not found_jmp:
        print(f'Failed to find jmp for {executable}', file=sys.stderr)
        exit(1)

    with open(gview_run_script_location_template) as f:
        template_script = f.read()
    to_replace = '\n'
    if lines_difference > 0:
        to_replace = "Key.Press(Down)\n" * lines_difference
    to_run_script = template_script.replace('${RUN}', to_replace)

    full_script_location = gview_run_script_location_template + '.gview'
    with open(full_script_location, 'w') as f:
        f.write(to_run_script)

    command_list = [gview_location_param, 'test', executable, full_script_location]
    command = ' '.join(command_list)
    result = subprocess.run(command, shell=True, stdout=subprocess.PIPE)
    out_result = result.stdout.decode('utf-8')
    return out_result


def collect_assistants_output(assistant_name, suffix=''):
    current_assistant_out = assistants_out
    tasks = []
    for file in os.listdir(binaries_out):
        file_location = os.path.join(binaries_out, file)
        if not os.path.isfile(file_location):
            continue
        # print('Processing: ' + file)
        problem_folder = os.path.join(current_assistant_out, file)
        if not os.path.exists(problem_folder):
            os.makedirs(problem_folder, exist_ok=True)
        out_file_name = f'{file}.{assistant_name}{suffix}.gview'
        gview_out_file = os.path.join(problem_folder, out_file_name)
        if os.path.exists(gview_out_file):
            print('Already exists: ' + file)
            continue
        tasks.append([file_location, gview_out_file])
        # output = run_gview(gview_location, file_location)
        # with open(gview_out_file, 'w') as f:
        #     f.write(output)
        # time.sleep(2)
    if len(tasks) == 0:
        print('No tasks!')
        return
    replicate_gview()
    distributed_tasks = distribute_tasks(tasks)

    with concurrent.futures.ThreadPoolExecutor(max_workers=thread_count) as executor:
        executor.map(lambda args: process_thread(*args), distributed_tasks.items())

    # global modified_ini
    # if modified_ini:
    #     modified_ini = utils.revert_ini(gview_ini_location, modified_ini)


def search_in_list(problem):
    if not os.path.exists(problems_input_location):
        return None
    with open(problems_input_location, 'r') as f:
        for line in f:
            if '.' not in line:
                continue
            line = line.split('.', maxsplit=1)
            if line[0].strip() == problem:
                return line[1].strip()
    return None


def process_assistants_output():
    errors_processing = []
    for problem in os.listdir(assistants_out):
        problem_folder = os.path.join(assistants_out, problem)
        if not os.path.isdir(problem_folder):
            continue
        problem_input = search_in_list(problem)
        if problem_input is None and CURRENT_RUN == 0:
            print('Failed to find problem: {}'.format(problem))
            continue
        json_output = os.path.join(problem_folder, 'output.json')
        # if os.path.exists(json_output):
        #     print('Already exists: ' + json_output)
        #     continue
        data = {}
        if CURRENT_RUN == 1:
            data['mitre_ids'] = {}
        assistant_mitre_ids = {}
        for file in os.listdir(problem_folder):
            file_location = os.path.join(problem_folder, file)
            if not os.path.isfile(file_location) or '.' not in file or file.endswith('.json'):
                continue
            assistant_name = file.split('.')[-2]
            with open(file_location, 'r') as f:
                found_name_selector = False
                names = []
                combined_text = ''
                for line in f:
                    if assistants_pattern in line:
                        found_name_selector = True
                        continue
                    if not found_name_selector:
                        continue
                    if '??????????????????????????????????????????????????' in line:
                        break
                    line = line.strip()
                    if len(line) == 0:
                        continue
                    line = line.split('?')[2].strip()
                    if len(line) == 0:
                        continue
                    names.append(line)
                    combined_text = f'{combined_text} {line}'
                data[assistant_name] = names
                if len(names) == 0:
                    print('Error processing: ' + file_location)
                    errors_processing.append(file_location)
            if CURRENT_RUN == 1:
                file_split = file.split('.')
                if len(file_split) > 3 and file_split[-1] == 'gview':
                    technique_name = file_split[0]
                    sub_technique_name = file_split[1]
                    mitre_ids = utils.find_mitre_ids(combined_text)
                    valid_mitre_ids = utils.filter_mitre_ids(mitre_ids, technique_name, sub_technique_name)
                    assistant_mitre_ids[assistant_name] = {'all': mitre_ids, 'valid': valid_mitre_ids}
        if problem_input:
            data['input'] = problem_input
        if assistant_mitre_ids:
            data['mitre_ids'] = assistant_mitre_ids

        with open(json_output, 'w') as f:
            json.dump(data, f, indent=4)
    if len(errors_processing) > 0:
        print(f"There were {len(errors_processing)} errors found")
        answer = input('Do you want to delete them? "y" for yes:  ')
        if answer == 'y':
            for file in errors_processing:
                os.remove(file)


def vote_best_assistant():
    for problem in os.listdir(assistants_out):
        problem_folder = os.path.join(assistants_out, problem)
        if not os.path.isdir(problem_folder):
            continue
        problem_input = search_in_list(problem)
        if problem_input is None:
            print('Failed to find problem: {}'.format(problem))
            continue
        json_output = os.path.join(problem_folder, 'output.json')
        voted_output = os.path.join(problem_folder, 'voted.json')
        if os.path.exists(voted_output):
            print('Already exists: ' + voted_output)
            continue
        with open(json_output, 'r') as f:
            data = json.load(f)
        voted_data = []
        assistants = ['gpt4o', 'gemini']
        print('Problem: ' + problem)
        for assistant in assistants:
            assistant_answers = data[assistant]
            problem = data['input']
            for answer in assistant_answers:
                print('Question: ' + problem)
                print('Answer: ' + answer)
                my_answer = input('Enter 1 for best category, 2 for code guess, 3 no clue: ')
                if my_answer not in ['1', '2', '3']:
                    print('Invalid answer')
                    continue
                voted_data.append({'assistant': assistant, 'category': my_answer, 'answer': answer})
        with open(voted_output, 'w') as f:
            json.dump(voted_data, f, indent=4)
            print('Voted data saved for problem: ' + problem)


def do_statistics():
    if CURRENT_RUN == 0:
        utils.do_statistics_run_0(assistants_out)
    else:
        utils.do_statistics_run_1(assistants_out)


def main():
    print('Starting RUN ' + str(CURRENT_RUN))
    suffix = ''
    # suffix = '_no_imports_no_strings'
    # suffix = '_yes_imports_no_strings'
    print('Suffix: ' + suffix)
    # collect_binaries()
    # collect_assistants_output('gpt4o', suffix)
    # collect_assistants_output('gemini', suffix)
    # process_assistants_output()
    # vote_best_assistant()
    do_statistics()
    pass


if __name__ == '__main__':
    main()

import os
import shutil
import sys
import csv
import re

technique_val_row = 0
src_name_row = 1
tactic_row = 6
techinque_row = 7
link_row = 9

mitre_intro_pattern = """// Link      = {}
// Technique = {}
// ID        = {}
// Tactics   = {}

"""
mitre_exec_cpp_pattern = "{}.{}E{}.cpp"


class MitreTechnique:
    def __init__(self, row):
        self.name = row[technique_val_row]
        self.tactic = row[tactic_row]
        self.technique = row[techinque_row]
        self.link = row[link_row]
        self.row = row
        self.count = 0
        self.exec_version = 0
        self.exec_patterns = []
        self.clean_patterns = []
        self.clean_pattern_names = ['exec00.txt', 'exec01.txt', 'exec02.txt', 'exec05.txt', 'exec10.txt']

    def read_patterns(self):
        patterns = os.listdir('patterns')
        for pattern in patterns:
            with open(os.path.join('patterns', pattern), 'r') as file:
                if pattern.startswith('exec'):
                    file_content = file.read()
                    self.exec_patterns.append(file_content)
                    if pattern in self.clean_pattern_names:
                        self.clean_patterns.append(file_content)

    def validate_first(self):
        if 'Technique' not in self.name or self.tactic != 'Tactic' or self.technique != 'Technique' or self.link != 'Link':
            print('Invalid CSV file')
            sys.exit(1)

    def is_exec(self):
        return self.name == 'exec'

    def generate_mitre(self, last_technique: "MitreTechnique", out_location, is_clean=False):
        if len(self.exec_patterns) == 0:
            self.read_patterns()

        if is_clean:
            intro = ''
        else:
            intro = mitre_intro_pattern.format(last_technique.link, last_technique.technique, last_technique.name,
                                               last_technique.tactic)
        for pattern in self.exec_patterns:
            if is_clean and pattern not in self.clean_patterns:
                continue
            version = 'V{}'.format(last_technique.exec_version)
            if not is_clean:
                version = ''
            file_name = mitre_exec_cpp_pattern.format(last_technique.name, version, self.count)
            file_loc = os.path.join(out_location, file_name)

            run_pattern = "RUN({});".format(self.row[1])
            regex_pattern = r'\$\{RUN\}'
            to_input = len(re.findall(regex_pattern, pattern))
            if to_input == 1:
                content = pattern.replace("${RUN}", run_pattern)
            elif to_input == 2:
                cmd_split = self.row[1].split(' ', maxsplit=1)
                cmd_split[0] = cmd_split[0] + '"'
                cmd_split[1] = '"' + cmd_split[1]
                content = pattern.replace("${RUN}", cmd_split[0], 1).replace("${RUN}", cmd_split[1], 1)
            else:
                print('Invalid pattern {}'.format(to_input))
                exit(1)
            with open(file_loc, 'w') as file:
                file.write(intro + content)
            self.count += 1

        # with open(file_loc, 'w') as file:
        #     file.write(mitre_pattern.format(self.link, self.technique, self.name, self.tactic))

        self.count += 1
        last_technique.exec_version += 1

    def is_clean(self):
        return self.name == 'clean'

    def is_src(self):
        return self.name == 'src'

    def copy_src(self, manual_sources_folder, out_folder):
        src_name = self.row[src_name_row]
        src_loc = os.path.join(manual_sources_folder, src_name)
        if not os.path.exists(src_loc):
            print(f'Failed to find src: {src_loc}')
            return
        src_out_loc = os.path.join(out_folder, src_name)
        shutil.copy(src_loc, src_out_loc)


# this function will change the key registry using the following mutations:
# initial value: "Software\Microsoft\Windows\CurrentVersion\Run"
# 1. "Software\Microsoft\Windows\CurrentVersion\Fun"
# 2. "Software\Microsoft\Windows\CurrentVersion\Tool"
# 3. "Software\Demo"
# 4. "Software\Run"
# 5. "Windows\CurrentVersion\Run"
# 6. "Software\Microsoft\Wundows\CurrentVersion\Run"
# 7. "Software\Microsoft\CurrentVersion\Run"

def clean_get_keys(initial_key_value):
    keys = []
    last_value = initial_key_value.split('\\')[-1]
    first_value = initial_key_value.split('\\')[0]
    char_list = list(initial_key_value)

    letter_change = char_list[:]
    letter_change[len(letter_change) - len(last_value)] = 'B'
    keys.append(''.join(letter_change))

    word_change = char_list[:len(char_list) - len(last_value)]
    word_change.extend(['T', 'o', 'o', 'l', '"'])
    keys.append(''.join(word_change))

    first_demo = char_list[:len(first_value)]
    first_demo.extend(['\\', '\\', 'D', 'e', 'm', 'o', '"'])
    keys.append(''.join(first_demo))

    first_last = char_list[:len(first_value)]
    first_last.extend(['\\', '\\'])
    first_last.extend(char_list[len(char_list) - len(last_value):])

    back_count = char_list.count('\\') // 2
    from_middle = [f for f in initial_key_value.split('\\')[back_count:] if len(f) > 0]
    from_middle = '\"' + '\\\\'.join(from_middle)
    keys.append(from_middle)

    if 'Windows' in initial_key_value:
        windows_change = initial_key_value.replace('Windows', 'Wundows')
        keys.append(windows_change)

        no_windows = initial_key_value.replace('Windows\\\\', '')
        keys.append(no_windows)
    return keys


def generate_clean_sources_from_manual_ones(manual_sources_folder, output_folder):
    for file in os.listdir(manual_sources_folder):
        if not file.startswith('T'):
            continue
        file_loc = os.path.join(manual_sources_folder, file)
        with open(file_loc, 'r') as f:
            content = f.read()
            if 'KEY_PATH' not in content or 'RegOpenKeyExA' not in content:
                continue
            keys = []
            key_line = ''
            for line in content.split('\n'):
                if 'KEY_PATH' in line:
                    key_line = line
                    line = line.split('KEY_PATH ')[1].strip()
                    keys = clean_get_keys(line)
                    break
            if len(keys) == 0:
                continue
            for index, key in enumerate(keys):
                file_name = file.replace('T', 'Clean')
                file_name = '.'.join(file_name.split('.', maxsplit=4)[:3])
                file_name += f'.E{index}.cpp'
                out_loc = os.path.join(output_folder, file_name)

                adjusted_key_line = f'#define KEY_PATH {key}\n'
                adjusted_content = content.replace(key_line, adjusted_key_line)
                with open(out_loc, 'w') as out_f:
                    out_f.write(adjusted_content)


def generate_all_sources(input_file, manual_sources_folder, output_folder):
    generate_clean_sources_from_manual_ones(manual_sources_folder, output_folder)
    with open(input_file, 'r') as csvfile:
        reader = csv.reader(csvfile, delimiter=',', quotechar='"')
        last_technique = MitreTechnique([''] * 10)
        for index, row in enumerate(reader):
            mitre = MitreTechnique(row)
            if index == 0:
                last_technique = mitre
                mitre.validate_first()
                continue
            if mitre.is_exec():
                mitre.generate_mitre(last_technique, output_folder)
            elif mitre.is_src():
                print(last_technique.name)
                mitre.copy_src(manual_sources_folder, output_folder)
            elif mitre.is_clean():
                mitre.generate_mitre(last_technique, output_folder, is_clean=True)
            else:
                last_technique = mitre


if __name__ == '__main__':
    if len(sys.argv) != 4:
        print('Usage: python generator.py <input file> <manual sources folder> <output folder>')
        sys.exit(1)
    generate_all_sources(sys.argv[1], sys.argv[2], sys.argv[3])

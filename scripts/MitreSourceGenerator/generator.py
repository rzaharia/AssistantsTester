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
mitre_exec_cpp_pattern = "{}.E{}.cpp"


class MitreTechnique:
    def __init__(self, row):
        self.name = row[technique_val_row]
        self.tactic = row[tactic_row]
        self.technique = row[techinque_row]
        self.link = row[link_row]
        self.row = row
        self.count = 0
        self.exec_patterns = []

    def read_patterns(self):
        patterns = os.listdir('patterns')
        for pattern in patterns:
            with open(os.path.join('patterns', pattern), 'r') as file:
                if pattern.startswith('exec'):
                    self.exec_patterns.append(file.read())

    def validate_first(self):
        if 'Technique' not in self.name or self.tactic != 'Tactic' or self.technique != 'Technique' or self.link != 'Link':
            print('Invalid CSV file')
            sys.exit(1)

    def is_exec(self):
        return self.name == 'exec'

    def generate_mitre(self, last_technique: "MitreTechnique", out_location):
        if len(self.exec_patterns) == 0:
            self.read_patterns()

        intro = mitre_intro_pattern.format(last_technique.link, last_technique.technique, last_technique.name,
                                           last_technique.tactic)
        for pattern in self.exec_patterns:
            file_name = mitre_exec_cpp_pattern.format(last_technique.name, self.count)
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


def generate_all_sources(input_file, manual_sources_folder, output_folder):
    with open(input_file, 'r') as csvfile:
        reader = csv.reader(csvfile, delimiter=',', quotechar='"')
        last_techinuqe = MitreTechnique([''] * 10)
        for index, row in enumerate(reader):
            mitre = MitreTechnique(row)
            if index == 0:
                last_techinuqe = mitre
                mitre.validate_first()
                continue
            if mitre.is_exec():
                mitre.generate_mitre(last_techinuqe, output_folder)
            elif mitre.is_src():
                print(last_techinuqe.name)
                mitre.copy_src(manual_sources_folder, output_folder)
            else:
                last_techinuqe = mitre


if __name__ == '__main__':
    if len(sys.argv) != 4:
        print('Usage: python generator.py <input file> <manual sources folder> <output folder>')
        sys.exit(1)
    generate_all_sources(sys.argv[1], sys.argv[2], sys.argv[3])

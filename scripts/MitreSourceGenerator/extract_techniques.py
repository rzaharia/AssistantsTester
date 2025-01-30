import os
import sys


def main(location):
    d = {}
    for src_name in os.listdir(location):
        if src_name.endswith(".cpp"):
            src = os.path.join(location, src_name)
            for line in open(src, "rt"):
                if line.startswith("// Tactics"):
                    l = line.split("=", 1)[1].strip().split(",")
                    if len(l) == 0:
                        print("Error on: ", src_name, " => ", line)
                    else:
                        for t in l:
                            t_name = t.strip()
                            if len(t_name) == 0: continue
                            if not t_name in d:
                                d[t_name] = 0
                            d[t_name] += 1
    items = list(d.items())
    items.sort(key=lambda x: x[0])
    for i in items:
        print((i[0] + " " * 100)[:30] + "& " + (str(i[1]) + " " * 10)[:5] + "\\\\")


##print(items)

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print(f'run {sys.argv[0]} <sources folder>')
    else:
        main(sys.argv[1])

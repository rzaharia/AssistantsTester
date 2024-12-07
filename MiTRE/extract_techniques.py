import os

d = {}
for name in os.listdir("."):
	if name.endswith(".cpp"):
		for line in open(name,"rt"):
			if line.startswith("// Tactics"):
				l = line.split("=",1)[1].strip().split(",")
				if len(l)==0:
					print("Error on: ",name," => ",line)
				else:
					for t in l:
						t_name = t.strip()
						if len(t_name)==0: continue
						if not t_name in d:
							d[t_name] = 0
						d[t_name] += 1
items = list(d.items())
items.sort(key = lambda x: x[0])
for i in items:
	print((i[0]+" "*100)[:30]+"& "+(str(i[1])+" "*10)[:5]+"\\\\")
##print(items)
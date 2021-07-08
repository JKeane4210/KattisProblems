solutions = {}

ops = ['/', '*', '+', '-']

for op1 in ops:
	for op2 in ops:
		for op3 in ops:
			prob = f"4 {op1} 4 {op2} 4 {op3} 4"
			res = eval(prob.replace("/", "//"))
			solutions[res] = prob

m = input()
m = int(m)

for i in range(m):
	n = input()
	n = int(n)
	if n in solutions:
		print(f"{solutions[n]} = {n}")
	else:
		print("no solution")

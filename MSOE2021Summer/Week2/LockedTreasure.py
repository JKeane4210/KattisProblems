def fact(n):
	return 1 if n == 0 else n * fact(n - 1)

def nCr(n, r):
	return fact(n) / (fact(r) * fact(n - r))

def main():
	c = input()
	c = int(c)
	for i in range(c):
		line = input()
		n = int(line.split(" ")[0])
		m = int(line.split(" ")[1])
		if (n == m):
			print(str(int(n)))
		else:
			print(str(int(nCr(n, n - m + 1))))

if __name__ == '__main__':
	main()
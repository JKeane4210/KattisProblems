def main():
	l1 = input()
	l2 = input()
	a = l1.count("S")
	b = l2.count("S")
	if a == 0 or b == 0:
		print(0)
		return
	else:
		print(a * b * "S(" + "0" + a * b * ")")
		return

if __name__ == '__main__':
	main()
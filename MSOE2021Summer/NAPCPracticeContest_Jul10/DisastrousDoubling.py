def main():
	n = input()
	n = int(n)
	testLine = input()
	tests = [int(test) for test in testLine.split(" ")]

	total = 1
	step = 0
	while (step < n):
		step = step + 1
		total = total * 2
		if (total < tests[step - 1]):
			print("error")
			return
		else:
			total -= tests[step - 1]
	print(total % 1000000007)
		
	

if __name__=='__main__':
	main()
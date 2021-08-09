count = input()
line = input()
nums = [int(val) for val in line.split(" ")]

minStart = -1
minTemp = 80 * 50 + 1
for i in range(len(nums) - 2):
	if max(nums[i], nums[i + 2]) < minTemp:
		minStart = i + 1
		minTemp = max(nums[i], nums[i + 2])

print(minStart, minTemp)
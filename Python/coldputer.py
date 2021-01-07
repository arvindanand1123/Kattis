num_vals = int(input())

nums = input()

output = 0

for i in nums.split(" "):
	if int(i) < 0:
		output += 1

print(output)

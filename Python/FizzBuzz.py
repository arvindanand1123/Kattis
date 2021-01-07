i=input().split(" ")
x=int(i[0])
y=int(i[1])
end=int(i[2])
for i in range(1, end+1):
	if(i % x == 0 and i % y == 0):
		print("FizzBuzz")
	elif(i % x == 0):
		print("Fizz")
	elif(i % y == 0):
		print("Buzz")
	else:
		print(i)

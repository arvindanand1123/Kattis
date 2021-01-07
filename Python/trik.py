def solve(ls):
	cups = [1,0,0]
	while(ls):
		s = ls[0]
		ls = ls[1:]
		if(s == 'A'):
			tmp = cups[0]
			cups[0] = cups[1]
			cups[1] = tmp
		elif(s == 'B'):	
			tmp = cups[1]
			cups[1] = cups[2]
			cups[2] = tmp
		elif(s == 'C'):
			tmp = cups[0]
			cups[0] = cups[2]
			cups[2] = tmp
	return cups


input_str = input()
sol = solve(input_str) 
for x in range(len(sol)):
	if(sol[x] == 1):
		print(x+1)
		break

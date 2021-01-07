mem = [[]]

def cardinal(terrain, loc, search_val):
	#loc_0 = row, loc_1 = col
	ret_ls = []
	#north
	if((loc[0] != 0) and (terrain[loc[0]-1][loc[1]] == search_val)):
		ret_ls.append([loc[0]-1, loc[1]])
	#south
	if((loc[0] != len(terrain)-1) and (terrain[loc[0]+1][loc[1]] == search_val)):
		ret_ls.append([loc[0]+1, loc[1]])
	
	#east
	if((loc[1] != len(terrain[0])-1) and (terrain[loc[0]][loc[1]+1] == search_val)):
		ret_ls.append([loc[0], loc[1]+1])
	
	#west
	if((loc[1] != 0) and (terrain[loc[0]][loc[1]-1] == search_val)):
		ret_ls.append([loc[0], loc[1]-1])
	return ret_ls
	

def search(terrain, loc, end, search_val):
	if((terrain[loc[0]][loc[1]] != search_val) or (terrain[end[0]][end[1]] != search_val)):
		return False
	if(loc == end):
		return True
	d = cardinal(terrain, loc, search_val)
	if(not d):
		return False
	for l in d:
		global mem
		if(not mem[l[0]][l[1]]):
			mem[l[0]][l[1]] = 1
			ret_val = search(terrain, l, end, search_val)
			if(ret_val):
				return True
	return False


def main():
	try:
		in1 = input().split(" ")
		r = int(in1[0])
		c = int(in1[1])
		terrain = [[None for i in range(c)] for j in range(r)]
		for i in range(0, r):
			val = input()
			tmp = []
			for x in val:
				tmp.append(int(x))
			terrain[i] = tmp

		cases = int(input())
		for i in range(cases):
			global mem
			mem = [[None for i in range(c)] for j in range(r)]
			vals = input().split(" ")
			start = [int(vals[0])-1, int(vals[1])-1]
			end = [int(vals[2])-1, int(vals[3])-1]
			decimal = search(terrain, start, end, 1)
			mem = [[None for i in range(c)] for j in range(r)]
			binary = search(terrain, start, end, 0)
			if(decimal):
				print("decimal")
			elif(binary):
				print("binary")
			else:
				print("neither")
	except:
		print("neither")
		



if __name__ == '__main__':
	main()
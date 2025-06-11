n = int(input())
a = [int(x) for x in input().split()]
 
def solve():
	d = -1
	for i in range(1, n):
		if abs(a[i] - a[i-1]) > 1:
			if d != -1 and d != abs(a[i]-a[i-1]):
				print('NO')
				return
			d = abs(a[i] - a[i-1])
  
	for i in range(1, n):
		x1, y1 = a[i]//d + 1, a[i]%d
		x2, y2 = a[i-1]//d+1, a[i-1]%d
		# print(x1, y1, x2,y2)
		if y1 == 0:
			y1 = d
			x1 -= 1
		if y2 == 0:
			y2 = d
			x2 -= 1
		if abs(x1-x2) + abs(y1-y2) != 1:
			print('NO')
			return 
	if d == -1:
		d = 1
	print('YES')
	print(10**9, d)
 
solve()

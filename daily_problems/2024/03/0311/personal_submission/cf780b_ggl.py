n = int(input())
xl = list(map(int , input().split()))
vl = list(map(int , input().split()))
l , r, eps = 0.0 , 1e9, 1e-7
while l + eps < r:
	t = (l + r) / 2
	lb , rb , ok = -1e10 , 1e10, 1
	for x, v in zip(xl, vl):
		if x - v * t > rb or x + v * t < lb:
			ok = 0
			break
		lb = max(lb , x - v * t)
		rb = min(rb , x + v * t)	
	if ok:
		r = t
	else:
		l = t + eps
	
print(l)

n, m = map(int, input().split())

ans = 0

for i in range(1, m + 1) :
	for j in range(1, m + 1) :
		k = (i * i + j * j) % m
		if k > 0 :
			continue
		
		ni = n // m + (n % m >= i)
		nj = n // m + (n % m >= j)
		
		ans += ni * nj

print(ans)
		
		

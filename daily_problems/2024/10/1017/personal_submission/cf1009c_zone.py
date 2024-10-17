n , m = MII() 
res = 0 
for _ in range(m):
    x, d = MII() 
    res += x * n
    if d > 0: 
        res += d * (n - 1) * n // 2 
    elif n & 1: 
        res += d * (n // 2 + 1) * (n // 2)
    else:
        res += d * ((n // 2 + 1) * (n // 2) // 2 + (n // 2 - 1) * (n // 2) // 2)

print(res / n)

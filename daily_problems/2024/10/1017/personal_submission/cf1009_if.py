def solve(n):
    return (n - 1) * n // 2 
n, m = map(int, input().split())
s = 0
l = []
for _ in range(m):
    x, d = map(int, input().split())
    s += n * x
    if d > 0:
        s += solve(n) * d
    else:
        cur = n // 2
        s += solve(cur + 1) * d + solve(n - cur) * d
print(s / n)
        

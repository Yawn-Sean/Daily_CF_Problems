n, k = map(int, input().split())
fib = [1, 1]
for _ in range(n-1):
    fib.append(fib[-1] + fib[-2])
ans = []
x = 1
while x <= n:
    if k <= fib[n-x]:
        ans.append(x)
        x += 1
    else:
        k -= fib[n-x]
        ans.append(x+1)
        ans.append(x)
        x += 2
print(*ans)
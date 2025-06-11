n, k = map(int, input().split())
x, r = divmod(n-1, k)
print(x*2 + min(r, 2))
for i in range(2, k+2):
    print(1, i)
for i in range(k+2, n+1):
    print(i-k, i)
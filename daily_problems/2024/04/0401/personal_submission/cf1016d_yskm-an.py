n, m = map(int, input().split())
arr = list(map(int, input().split()))
brr = list(map(int, input().split()))
ans1 = 0
ans2 = 0
for i in range(n):
    ans1 ^= arr[i]
for j in range(m):
    ans2 ^= brr[j]
if ans1 != ans2:
    print('NO')
    exit(0)
res = [[0] * m for _ in range(n)]
for i in range(n - 1):
    res[i][m - 1] = arr[i]
for j in range(m - 1):
    res[n - 1][j] = brr[j]
for i in range(n - 1):
    res[-1][-1] ^= arr[i]
res[-1][-1] ^= brr[-1]
print('YES')
for arr in res:
    print(*arr)

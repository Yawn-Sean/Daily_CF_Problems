t = ix()
for i in range(t):
    n = ix()
    ans = [[1] * n for i in range(n)]
    for i in range(n):
        for j in range(i):
            ans[i][j] += 2
    for i in range(n % 2, n):
        ans[n - 1][i] += 1
    for x in ans:
        print(*x)

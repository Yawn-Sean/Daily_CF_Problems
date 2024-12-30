def main():
    M = 2 * 10 ** 9
    n,m,k,q = map(int, input().split())
    g = [[M] * (m + 1) for _ in range(n + 1)]
    for _ in range(q):
        x,y,t = map(int, input().split())
        g[x][y] = t
    p = [[0] * (m + 1) for _ in range(n + 1)]
    l,r = 0, M
    while l < r:
        mid = (l + r) // 2
        for i in range(n + 1):
            for j in range(m + 1):
                p[i][j] = 1 if g[i][j] <= mid else 0
        for i in range(n + 1):
            for j in range(1, m + 1):
                p[i][j] += p[i][j-1]
        
        for i in range(1, n + 1):
            for j in range(m + 1):
                p[i][j] += p[i-1][j]
        f = False
        for i in range(n - k + 1):
            for j in range(m - k + 1):
                if p[i+k][j+k] - p[i][j+k] - p[i+k][j] + p[i][j] == k * k:
                    f = True
        if f:
            r = mid
        else:
            l = mid + 1
    print(l if l < M else -1)


main()
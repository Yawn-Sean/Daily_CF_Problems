def main():
    n,m,k = map(int,input().split())
    g = []
    for _ in range(n):
        s = input()
        s = [int(i) for i in s]
        g.append(s)
    cnt = [[0]*m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if g[i][j] == 1 and 0 < i < n-1 and 0 < j < m-1:
                if g[i-1][j] and g[i+1][j] and g[i][j-1] and g[i][j+1]:
                    cnt[i][j] = 1
    # 枚举上下界
    # 双指针表示左右界
    ans = 0
    for xl in range(n):
        row = [0]*m
        for xr in range(xl+2,n):
            for i in range(m):
                if cnt[xr - 1][i]:
                    row[i] += 1
            cur = 0
            r = 1
            for l in range(1, m-1):
                while r < m-1 and cur < k:
                    cur += row[r]
                    r += 1
                if cur < k:
                    break
                ans += m - r
                cur -= row[l]
    print(ans)

main()
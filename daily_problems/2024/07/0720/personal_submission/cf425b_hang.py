def main():
    n,m,k = map(int,input().split())
    g = []
    for _ in range(n):
        g.append(list(map(int,input().split())))
    ans = k + 1
    for i in range(m):
        res = 0
        for j in range(m):
            cnt = 0
            for x in range(n):
                if g[x][i] == g[x][j]: cnt += 1
            res += min(cnt,n-cnt)
        ans = min(ans,res)
    print(ans if ans <= k else -1)
main()
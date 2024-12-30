def main():
    n,m,k = map(int,input().split())
    g = [list(map(int, input().split())) for _ in range(n)]
    ans = 0
    cnt = 0
    pre = [0] * (n + 1)
    for i in range(m):
        for j in range(n):
            pre[j + 1] = pre[j] + g[j][i]
        res = 0
        idx = 0
        
        for j in range(n):
            if g[j][i]:
                v = pre[min(j + k, n)] - pre[j]
                if v > res:
                    res = v
                    idx = pre[j]
        ans += res
        cnt += idx
    print(ans, cnt)
main()
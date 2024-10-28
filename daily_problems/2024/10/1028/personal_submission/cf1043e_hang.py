def main():
    n,m = map(int,input().split())
    g = []
    tot_x,tot_y = 0,0
    for _ in  range(n):
        g.append(list(map(int,input().split())))
        tot_y += g[-1][-1]
    r = sorted(range(n),key=lambda x:g[x][0] - g[x][1]) 
    ans = [0] * n
    for i in range(n):
        pos = r[i]
        tot_y -= g[pos][-1]
        ans[pos] = tot_x + i * g[pos][-1] + tot_y + g[pos][0] * (n - i - 1)
        tot_x += g[pos][0]
    for _ in range(m):
        u,v = map(lambda x:int(x) - 1,input().split())
        val = min(g[u][0] + g[v][1], g[u][1] + g[v][0])
        ans[u] -= val
        ans[v] -= val
    print(*ans)

main()
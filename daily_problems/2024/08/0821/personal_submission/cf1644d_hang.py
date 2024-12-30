vis_x = [0] * (2 * 10 ** 5)
vis_y = [0] * (2 * 10 ** 5)
def main():
    n,m,k,q = map(int,input().split())
    mod = 998244353
    g = []
    for i in range(q):
        x,y = map(lambda i: int(i) - 1,input().split())
        g.append([x,y])
    r,c = 0, 0
    ans = 1
    for i in range(q-1, -1, -1):
        x,y = g[i]
        if (not vis_x[x] and c != m)  or (not vis_y[y] and r != n):
            ans = (ans * k) % mod
            if not vis_x[x]:
                vis_x[x] = 1
                r += 1
            if not vis_y[y]:
                vis_y[y] = 1
                c += 1
    for i in range(q):
        vis_x[g[i][0]] = 0
        vis_y[g[i][1]] = 0
    print(ans)


t = int(input())
for _ in range(t):
    main()
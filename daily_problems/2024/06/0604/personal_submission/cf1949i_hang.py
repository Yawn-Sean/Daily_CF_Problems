
def main():
    n = int(input())
    g = []
    for _ in range(n):
        x,y,r = map(int,input().split())
        g.append((x,y,r))
    path = [[] for _ in range(n)]
    for i in range(n):
        for j in range(i+1,n):
            x1,y1,r1 = g[i]
            x2,y2,r2 = g[j]
            dx = x1-x2
            dy = y1-y2
            dr = r1+r2
            if dx**2+dy**2 == dr**2:
                path[i].append(j)
                path[j].append(i)

    color = [-1] *n
    d = [0,0]
    f = True
    def dfs(v,p):
        color[v] = p
        d[p] += 1
        nonlocal f
        for u in path[v]:
            if color[u] == -1:
                dfs(u,p^1)
            else:
                if color[u] == color[v]:
                    f = False


    for i in range(n):
        if color[i] == -1:
            f = True
            d = [0,0]
            dfs(i, 0)
            if f and d[0] != d[1]:
                print("YES")
                return

    print("NO")
if __name__ == '__main__':
    main()
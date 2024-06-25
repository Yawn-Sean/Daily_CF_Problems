def main():
    n,d = map(int,input().split())
    a = [0] + list(map(int,input().split())) + [0]
    g = []
    for _ in range(n):
        g.append(list(map(int,input().split())))
    dist = [-1] *(n)
    dist[0] = 0

    vis = [False] * (n)
    vis[0] = True
    
    def cost(i,j):
        return (abs(g[i][0] - g[j][0]) + abs(g[i][1] - g[j][1]) ) * d
    
    u = 0 
    for _ in range(n - 1):
        v = -1
        for i in range(n):
            if not vis[i]:
                if dist[i] == -1 or cost(u,i) - a[i] + dist[u] < dist[i]:
                    dist[i] = cost(u,i) - a[i] + dist[u]
                if v == -1 or dist[v] > dist[i]:
                    v = i
        vis[v] = True
        u = v
    print(dist[-1])

main()
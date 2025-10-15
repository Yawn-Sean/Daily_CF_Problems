"""
思路：首先用队列记录叶子节点，接着遍历叶子节点，记录已经走过的点数和每个结点被访问的次数。

在遍历过程中判断两种不满足的情况，直接结束程序

最后根据走过的最多点数为k + 1判断是否满足题意。


"""


    n, k = map(int, input().split())
    g = [[] for _ in range(n)]
    
    for _ in range(n - 1):
        u, v = map(int, input().split())
        g[u - 1].append(v - 1)
        g[v - 1].append(u - 1)
    q = deque(i for i in range(n) if len(g[i]) == 1)
    dist = [0] * n
    for i in q: dist[i] = 1
    l, c = 0, [0] * n
    
    while q:
        u = q.popleft()
        l = max(l, dist[u])
        
        if dist[u] > 1 and (c[u] < 3 or c[u] < len(g[u]) - 1):
            print("No")
            exit()
        
        for v in g[u]:
            if dist[u] > 1 and dist[v] == dist[u] - 1:
                continue
            if dist[v] == dist[u] or dist[v] > dist[u] + 1:
                print("No")
                exit()
            
            c[v] += 1
            if not dist[v]:
                dist[v] = dist[u] + 1
                q.append(v)
    
    print("Yes" if l == k + 1 else "No")

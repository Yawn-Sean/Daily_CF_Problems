# Submission link: https://codeforces.com/gym/102700/submission/388217226
def main():
    n, m = MII()
    a, b, k = MII()
    
    path = [[] for _ in range(n)]
    rev_path = [[] for _ in range(n)]
    
    for _ in range(m):
        u, v, w = MII()
        path[u].append(w * n + v)
        rev_path[v].append(w * n + u)
    
    def f(d, u, layer):
        return (d * n + u) * (k + 1) + layer
    
    def shortest_path(graph, start):
        dis = [[inf] * n for _ in range(k + 1)]
        dis[0][start] = 0
        
        pq = [f(0, start, 0)]
        
        while pq:
            msk = heappop(pq)
            msk, layer = divmod(msk, k + 1)
            d, u = divmod(msk, n)
            
            if dis[layer][u] == d:
                for emsk in graph[u]:
                    w, v = divmod(emsk, n)
                    
                    if dis[layer][v] > dis[layer][u] + w:
                        dis[layer][v] = dis[layer][u] + w
                        heappush(pq, f(dis[layer][v], v, layer))
                    
                    if layer < k and dis[layer + 1][v] > dis[layer][u]:
                        dis[layer + 1][v] = dis[layer][u]
                        heappush(pq, f(dis[layer + 1][v], v, layer + 1))
    
        for i in range(1, k + 1):
            for u in range(n):
                dis[i][u] = fmin(dis[i][u], dis[i - 1][u])
        
        return dis
    
    def solve(start):
        v1 = shortest_path(path, start)
        v2 = shortest_path(rev_path, start)
        
        ans = [inf] * n
        
        for i in range(k + 1):
            for u in range(n):
                ans[u] = fmin(ans[u], v1[i][u] + v2[k - i][u])
        
        return ans
    
    wa = solve(a)
    wb = solve(b)
    
    ans = inf
    chosen = -1
    
    for u in range(n):
        if u != a and u != b and wa[u] + wb[u] < ans:
            ans = wa[u] + wb[u]
            chosen = u
    
    if ans < inf: print(chosen, ans)
    else: print('>:(')
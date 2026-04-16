# Submission link: https://codeforces.com/gym/105501/submission/371339432
def main():
    n = II()
    graph = LGMI()
    
    rev_graph = [[] for _ in range(n)]
    for i in range(n):
        rev_graph[graph[i]].append(i)
    
    indeg = [0] * n
    for x in graph:
        indeg[x] += 1
    
    stk = [i for i in range(n) if indeg[i] == 0]
    while stk:
        u = stk.pop()
        indeg[graph[u]] -= 1
        if indeg[graph[u]] == 0:
            stk.append(graph[u])
    
    vis = [0] * n
    
    dp0 = [0] * n
    dp1 = [0] * n
    
    ans = 0
    
    for i in range(n):
        if indeg[i] and not vis[i]:
            cycle = [i]
            vis[i] = 1
            
            while graph[cycle[-1]] != i:
                cycle.append(graph[cycle[-1]])
                vis[cycle[-1]] = 1
            
            v0s = []
            v1s = []
            
            for u in cycle:
                que = [u]
                for x in que:
                    for y in rev_graph[x]:
                        if not vis[y]:
                            vis[y] = 1
                            que.append(y)
                
                for x in reversed(que):
                    dp1[x] = 1
                    for y in rev_graph[x]:
                        if indeg[y] == 0:
                            dp0[x] += fmax(dp0[y], dp1[y])
                            dp1[x] += dp0[y]
    
                v0s.append(dp0[u])
                v1s.append(dp1[u])
            
            k = len(v0s)
            res = 0
            
            val0 = 0
            val1 = 0
            
            for i in range(1, k):
                val0, val1 = fmax(val0, val1) + v0s[i], val0 + v1s[i]
            
            res = fmax(res, v0s[0] + fmax(val0, val1))
    
            val0 = 0
            val1 = 0
            
            for i in range(k - 1):
                val0, val1 = fmax(val0, val1) + v0s[i], val0 + v1s[i]
            
            res = fmax(res, v0s[-1] + fmax(val0, val1))
            
            ans += res
    
    print(n - ans)
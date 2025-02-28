# Submission link: https://codeforces.com/contest/263/submission/306936249
def main():
    n = II()
    path = [set() for _ in range(n + 1)]

    for _ in range(2 * n):
        u, v = MII()
        path[u].add(v)
        path[v].add(u)

    if len(path[1]) > 4: exit(print(-1))
    else:
        for u in path[1]:
            for v in path[1]:
                if u != v and u in path[v]:
                    vis = [0] * (n + 1)
                    cycle = [1, u, v]
                    vis[1] = 1
                    vis[u] = 1
                    vis[v] = 1
                    
                    for _ in range(n - 3):
                        x = cycle[-2]
                        y = cycle[-1]
                        
                        for z in path[y]:
                            if not vis[z] and x in path[z]:
                                cycle.append(z)
                                vis[z] = 1
                                break
                        
                    
                    if len(cycle) == n and cycle[0] in path[cycle[-2]] and cycle[0] in path[cycle[-1]] and cycle[1] in path[cycle[-1]]:
                        exit(print(' '.join(map(str, cycle))))
        
        print(-1)
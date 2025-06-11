import sys
RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
枚举和1相连的两个点作为圆上最初的三个连续点，然后下一个点是和点2点3相连，不同于1的点
'''
n = RI()
path = [set() for _ in range(n + 1)]

for _ in range(2 * n):
    u, v = RII()
    path[u].add(v)
    path[v].add(u)

if max(len(x) for x in path) > 4:
    exit(print(-1))
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
                
                if len(cycle) == n and cycle[0] in path[cycle[-2]] and cycle[0] in path[cycle[-1]] and cycle[1] in \
                        path[cycle[-1]]:
                    exit(print(' '.join(map(str, cycle))))
    
    print(-1)
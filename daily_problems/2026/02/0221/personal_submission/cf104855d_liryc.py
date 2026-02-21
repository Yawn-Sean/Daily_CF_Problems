'''
https://codeforces.com/gym/104855/submission/363760691
'''
# graph
def solve(n: int, m: int, edges: list[list[int]]):
    ug = [[] for _ in range(n)]
    for u, v, c in edges:
        u, v = u - 1, v - 1
        ug[u].append([v, c])
    vis = [0] * n
    vis[0] = -1
    ans = [1]
    qu = deque()
    qu.append(0)
    while qu:
        u = qu.popleft()
        for v, c in ug[u]:
            if c != vis[u] and vis[v] >= 0 and c != vis[v]:
                if vis[v] == 0:
                    vis[v] = c
                    ans.append(v + 1)
                else:
                    vis[v] = -1
                qu.append(v)
    ans.sort()
    return ans

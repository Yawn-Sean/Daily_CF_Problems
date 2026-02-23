'''
https://codeforces.com/gym/104855/submission/363785580
'''
# graph
def solve(n: int, m: int, tg: list[list[list[int]]]):
    vis = [0] * n
    vis[0] = -1
    qu = deque()
    qu.append(0)
    while qu:
        u = qu.popleft()
        for v, c in tg[u]:
            if c != vis[u] and vis[v] >= 0 and c != vis[v]:
                if vis[v] == 0:
                    vis[v] = c
                else:
                    vis[v] = -1
                qu.append(v)
    for i in range(n):
        if vis[i]:
            yield i + 1

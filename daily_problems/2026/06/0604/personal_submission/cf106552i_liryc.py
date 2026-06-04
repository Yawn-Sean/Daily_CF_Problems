'''
https://codeforces.com/gym/106552/submission/377246245
Floyd / SPFA
'''
pmin = lambda x, y: x if y < 0 or x >= 0 and x <= y else y
def solve(n: int, m: int, q: int, la: list[list[int]], qa: list[list[int]]) -> list[int]:
    sg = [set() for _ in range(m)]
    for a in la:
        for u, v in combinations(a, 2):
            sg[u - 1].add(v - 1)
            sg[v - 1].add(u - 1)
    vis = [[-1] * m for _ in range(m)]
    for k in range(m):
        que = [k]
        vis[k][k] = 0
        for u in que:
            for v in sg[u]:
                if vis[k][v] == -1:
                    vis[k][v] = vis[k][u] + 1
                    que.append(v)
    def qry(u, v):
        ans = -1
        for x in la[u - 1]:
            for y in la[v - 1]:
                ans = pmin(ans, vis[x - 1][y - 1])
        return ans
    return [qry(u, v) for u, v in qa]

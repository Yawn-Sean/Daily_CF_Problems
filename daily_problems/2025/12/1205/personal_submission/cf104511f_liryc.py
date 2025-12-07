'''
https://codeforces.com/gym/104511/submission/352395926
'''
# dijkstra
def solve(n: int, m: int, v: int, s: str, trades: list[list[int]]) -> float:
    mp = int("0b" + s[::-1], 2)
    def visit(i):
        nonlocal mp
        return mp >> i - 1 & 1
    def check(i):
        nonlocal mp
        mp ^= 1 << i - 1
    if visit(1):
        return v
    g = [[] for _ in range(n + 1)]
    for i, (a, x, b, y, c, z) in enumerate(trades):
        g[x].append(i)
        g[y].append(i)
    cost = [0] * (n + 1)
    hp = []
    for u in range(1, n + 1):
        if visit(u):
            cost[u] = 1
            hp.append(1 << 6 | u)
    mp = 0
    while hp:
        u = heappop(hp) & 63
        if u == 1:
            return v / cost[1]
        if not visit(u):
            check(u)
            for i in g[u]:
                a, x, b, y, c, z = trades[i]
                if visit(x) and visit(y) and not visit(z):
                    c = cost[x] * a + cost[y] * b
                    if cost[z] == 0 or cost[z] > c:
                        cost[z] = c
                        heappush(hp, c << 6 | z)
    return 0

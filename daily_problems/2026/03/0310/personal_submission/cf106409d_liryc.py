'''
https://codeforces.com/gym/106409/submission/366110061
'''
# simple graph search
def solve(n: int, m: int, edges: list[list[int]]) -> list[int]:
    g = [[] for _ in range(n)]
    for u, v in edges:
        g[u].append(v)
        g[v].append(u)
    for b, c in edges:
        for a in g[b][:4]:
            if a != c:
                for d in g[c]:
                    if d != b and d != a:
                        return [a + 1, b + 1, c + 1, d + 1]
    return [-1]

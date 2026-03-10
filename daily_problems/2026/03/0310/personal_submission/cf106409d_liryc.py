'''
20260310 Y1 1300
simple search
'''
def solve(n: int, m: int, g: list[list[int]]) -> list[int]: 
    for u in range(n):
        for v in g[u]:
            for x in g[u][:4]:
                for y in g[v][:4]:
                    if x != v and y != u and x != y:
                        return [x + 1, u + 1, v + 1, y + 1]
    return [-1]

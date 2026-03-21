'''
20260321 Y1 1600
'''
def solve(n: int, m: int, edges: list[list[int]]) -> int: 
    uni = UnionFind(n * 2)
    ans = 1
    cur = []
    for u, v in edges:
        if uni.check(u, v):
            for x in cur:
                uni.back(x)
                uni.back(x + n)
            ans += 1
            cur.clear()
        uni.union(u, v + n)
        uni.union(v, u + n)
        cur.append(u)
        cur.append(v)
    return ans
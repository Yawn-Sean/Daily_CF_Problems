'''
https://codeforces.com/gym/104009/submission/367593232
'''
def solve(n: int, m: int, edges: list[list[int]]) -> int:
    uni = UnionFind(n << 1)
    ans = 1
    for u, v in edges:
        if uni.check(u, v):
            uni.reset()
            ans += 1
        uni.union(u, v + n)
        uni.union(v, u + n)    
    return ans

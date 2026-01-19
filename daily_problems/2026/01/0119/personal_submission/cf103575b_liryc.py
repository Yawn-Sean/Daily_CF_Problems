'''
https://codeforces.com/gym/103575/submission/358728105
'''
def solve(n: int, m: int, edges: list[list[int]]) -> list[int]: 
    uni1 = UnionFind(n)
    uni2 = UnionFind(n)
    
    for i, (u, v, w) in enumerate(edges):
        if not w & 1:
            uni1.union(u, v)
    
    vis = [False] * m
    even = 1
    
    for i, (u, v, w) in enumerate(edges):
        if w & 1 and not uni1.check(u, v):
            uni1.union(u, v)
            uni2.union(u, v)
            vis[i] = True
            even ^= 1
    
    if not even:
        for i, (u, v, w) in enumerate(edges):
            if w & 1 and not vis[i] and not uni2.check(u, v):
                uni2.union(u, v)
                vis[i] = True
                even ^= 1
                break
    
    if not even: 
        return []
    else:
        for i, (u, v, w) in enumerate(edges):
            if not w & 1 and not uni2.check(u, v):
                uni2.union(u, v)
                vis[i] = True
        
        return [i + 1 for i in range(m) if vis[i]]

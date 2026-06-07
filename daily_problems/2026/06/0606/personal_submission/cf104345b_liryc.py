'''
https://codeforces.com/gym/104345/submission/377452715
tree, dsu
'''

uni = UnionFind(1)
tg = []
pr = []
vis = []

def init():
    global uni, tg, pr, vis
    n = int(input())
    tg = [[] for _ in range(n + 1)]
    for _ in range(n - 1):
        u, v = map(int, input().split())
        tg[u].append(v)
        tg[v].append(u)
    stk, pr = [1], [0] * (n + 1)
    while stk:
        u = stk.pop()
        for v in tg[u]:
            if v != pr[u]:
                pr[v] = u
                stk.append(v)
    uni = UnionFind(n + 1)
    vis = [0] * (n + 1)

def solve(s: list[int]) -> int:       
    global uni, vis     
    for u in s:
        vis[u] = 1
    for u in s:
        p = pr[u]
        if p and vis[p]:
            uni.union(u, p)
    ans = 0
    for u in s:
        if uni.parent[u] < 0:
            sz = uni.size(u)
            ans += sz * (sz - 1) >> 1
    for u in s:
        vis[u] = 0
    uni.reset(s)
    return ans

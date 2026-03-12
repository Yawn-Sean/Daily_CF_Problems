'''
https://codeforces.com/gym/105453/submission/366341821
'''
# Prim-MST
def solve(n: int, A: list[list[int]]) -> int:
    vis = [False] * n
    hp = [enc(A[i][i], i) for i in range(n)]
    heapify(hp)
    ans = 0
    for _ in range(n):
        w, u = dec(heappop(hp))
        while vis[u]:
            w, u = dec(heappop(hp))
        ans += w
        vis[u] = True
        for v in range(n):
            if not vis[v]:
                heappush(hp, enc(A[u][v], v))
    return ans

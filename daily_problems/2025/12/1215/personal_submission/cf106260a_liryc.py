'''
https://codeforces.com/gym/106260/submission/353457451
'''
parent = [0] * 200000
depth = [0] * 200000
def solve(n: int, tg: list[list[int]]) -> int:
    global parent, depth
    MOD = 998244353
    depth[0] = 1
    parent[0] = -1
    stk = [0]
    while stk:
        u = stk.pop()
        for v in tg[u]:
            if v != parent[u]:
                parent[v] = u
                depth[v] = depth[u] + 1
                stk.append(v)
    ans = 0
    for u in range(n):
        d = depth[u]
        ans += pow(d, -1, MOD)
    return ans % MOD
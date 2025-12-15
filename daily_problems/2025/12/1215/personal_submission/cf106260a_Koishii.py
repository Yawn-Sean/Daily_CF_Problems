mod = 998244353

def soviet():
    n = int(input())
    e = [[] for _ in range(n + 1)]
    dep = [0] * (n + 1)
    for _ in range(n - 1):
        u, v = map(int, input().split())
        e[u] += [v]
        e[v] += [u]

    ans = 0
    def dfs(u, fa):
        dep[u] = dep[fa] + 1
        ans += pow(dep[u], mod - 2, mod)
        for v in e[u]:
            if v == fa:
                continue
            dfs(v, u)
            
    dfs(1, 0)
    print(ans % mod)

MT = int(input())
for _ in range(MT):
    soviet()

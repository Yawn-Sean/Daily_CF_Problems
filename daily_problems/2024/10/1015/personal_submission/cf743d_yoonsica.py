# https://codeforces.com/contest/743/submission/285979449
n = RI()
a = RILIST()
g = defaultdict(list)
for _ in range(n - 1):
    u, v = RII()
    g[u].append(v)
    g[v].append(u)

ans = -inf

@bootstrap
def dfs(u, fa):
    s = a[u - 1]
    global ans
    mx1 = mx2 = -inf
    for v in g[u]:
        if v != fa:
            tv, sv = yield dfs(v, u)
            if tv >= mx1:
                mx2 = mx1
                mx1 = tv
            elif tv > mx2:
                mx2 = tv
            s += sv
    # 两个儿子肯定不相交,更新答案
    if mx1 > -inf and mx2 > -inf:
        ans = mx(ans, mx1 + mx2)
    # 返回u的最大子树，子树和
    yield mx(mx1, s), s


dfs(1, 0)
print(ans if ans > -inf else 'Impossible')

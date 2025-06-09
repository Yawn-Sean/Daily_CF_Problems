# Submission link: https://codeforces.com/problemset/submission/82/318680082
def main():
    n = II()
    nums = LII()

    us = []
    vs = []
    cs = []

    path = [[] for _ in range(n)]
    for i in range(n - 1):
        u, v, c = MII()
        u -= 1
        v -= 1
        us.append(u)
        vs.append(v)
        cs.append(c)
        path[u].append(i)
        path[v].append(i)

    cnt = [[0] * (n + 1) for _ in range(n)]

    parent = [-1] * n
    parent_cnt = [0] * n

    stk = [0]
    while stk:
        u = stk.pop()
        for eid in path[u]:
            v = us[eid] + vs[eid] - u
            c = cs[eid]
            if parent[u] != v:
                parent[v] = u
                parent_cnt[v] = c
                stk.append(v)

    ans = [-1] * n

    for i in sorted(range(n), key=lambda x: nums[x]):
        t = 0
        u = i

        while u:
            while cnt[u][t] == parent_cnt[u]:
                t += 1
            cnt[u][t] += 1
            t += 1
            u = parent[u]

        ans[i] = t

    print(' '.join(map(str, ans)))
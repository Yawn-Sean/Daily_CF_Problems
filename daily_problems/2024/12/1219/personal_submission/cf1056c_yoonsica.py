"""
https://codeforces.com/contest/1056/submission/297194370
思路：
先手就先选固定搭配里大的那个，直到把固定搭配选完，然后剩下元素里选最大的
后手就看对面选不选固定搭配，选固定的，我们没的选，直到对面不选固定的搭配，此时和我们先手情况一样了
"""
n, m = RII()
n *= 2
a = [0] + RILIST()
g = defaultdict(int)
c = []
s = 0
for _ in range(m):
    x, y = RII()
    g[x] = y
    g[y] = x

b = [0] + sorted(range(1, n + 1), key=lambda x: -a[x])

vis = [0] * (1 + n)
t = RI()
if t == 1:
    # 我们先手，直接选搭配
    for k, v in g.items():
        if vis[k]:
            continue
        vis[k] = 1
        print(k if a[k] > a[v] else v, flush=True)
        vis[v] = 1
        RI()
    i = 1
    while i <= n:
        if vis[b[i]]:
            i += 1
        else:
            print(b[i], flush=True)
            vis[b[i]] = 1
            vis[RI()] = 1
            i += 1
else:
    # 后手
    cnt = 0
    while cnt < n:
        x = RI()
        vis[x] = 1
        cnt += 1
        if x in g:
            print(g[x], flush=True)
            vis[g[x]] = 1
            cnt += 1
        else:
            for k, v in g.items():
                if vis[k]:
                    continue
                vis[k] = 1
                print(k if a[k] > a[v] else v, flush=True)
                vis[v] = 1
                RI()
                cnt += 2
            i = 1
            while i <= n:
                if vis[b[i]]:
                    i += 1
                else:
                    print(b[i], flush=True)
                    vis[b[i]] = 1
                    cnt += 1
                    i += 1
                    if cnt < n:
                        vis[RI()] = 1
                        cnt += 1

'''
https://codeforces.com/contest/269/submission/273972690
269C
2024/8/2 Y2
2100
网络流
'''

n, m = map(int, input().split())
ans = [-1] * m
d = {}
g = [[] for _ in range(n + 1)]
for i in range(m):
    a, b, c = map(int, input().split())
    g[a].append((b, c))
    g[b].append((a, c))
    d[(a, b)] = (i, 0)
    d[(b, a)] = (i, 1)
s = [sum(c for _, c in v) for v in g]
stk = [1]
vis = set([1])
ic = [0] * (n + 1)
while stk:
    t = stk.pop()
    for r, c in g[t]:
        if not r in vis:
            i, x = d[(t, r)]
            ans[i] = x
            ic[r] += c
            if r != n and ic[r] == s[r] // 2: # WA: forgot r != n
                vis.add(r)
                stk.append(r)
print(*ans, sep='\n')
"""
problem url   : https://codeforces.com/problemset/problem/1472/E
submission url: https://codeforces.com/contest/1472/submission/284107875
"""

t = II() 
outs = [] 
for _ in range(t): 
    n = II() 
    hs, ws = [], []
    for _ in range(n):
        h, w = MII()
        h, w = min(h, w), max(h, w) 
        hs.append(h)
        ws.append(w)
    ans = [0] * n
    indices = sorted(range(n), key=lambda x: (hs[x], -ws[x]))
    mn = -1 
    for i in indices:
        if mn == -1 or ws[mn] >= ws[i]:
            ans[i] = -1
            mn = i
        else:
            ans[i] = mn + 1 
    outs.append(' '.join(str(x) for x in ans))

print('\n'.join(outs))

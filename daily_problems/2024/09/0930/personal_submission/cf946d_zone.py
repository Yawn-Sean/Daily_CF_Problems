"""
problem url   : https://codeforces.com/problemset/problem/946/D
submission url: https://codeforces.com/contest/946/submission/283719946
"""
n, m, k = MII() 
scs = [I() for _ in range(n)]

def f(i, j):
    return i * (k + 1) + j

dp = [inf] * (n + 1) * (k + 1)
dp[f(0, 0)] = 0 

for i, s in enumerate(scs): 
    idx = [t for t in range(m) if s[t] == '1']
    ln = len(idx)

    if ln: 
        cnt = [inf] * (ln + 1)
        cnt[ln] = 0
        for l in range(ln):
            for i_ in range(l + 1): 
                j_ = ln - l + i_ - 1
                cnt[l] = min(cnt[l], idx[j_] - idx[i_] + 1)
        
        for j in range(k + 1):
            if dp[f(i, j)] == inf: break
            for v in range(ln + 1):
                if j + v > k: break 
                # print(i + 1, j + v, n, m, len(dp), f(i + 1, j + v))
                dp[f(i + 1, j + v)] = min(dp[f(i + 1, j + v)], dp[f(i, j)] + cnt[v])
    else:
        for j in range(k + 1):
            if dp[f(i, j)] == inf: continue
            dp[f(i + 1, j)] = dp[f(i, j)]
print(min(dp[f(n, i)] for i in range(k + 1)))

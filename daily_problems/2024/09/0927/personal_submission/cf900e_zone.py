"""
problem url   : https://codeforces.com/problemset/problem/900/E
submission url: https://codeforces.com/contest/900/submission/283141563
"""

n = II() 
s = I() 
m = II() 

cnt_a, cnt_b = [0] * (n + 1), [0] * (n + 1)
cnt_q = [0] * (n + 1)

for i in range(n):
    cnt_q[i + 1] = cnt_q[i] + (s[i] == '?')

for i in range(n - 1, -1, -1):
    cnt_a[i] = cnt_b[i + 1] + 1 if s[i] != 'b' else 0
    cnt_b[i] = cnt_a[i + 1] + 1 if s[i] != 'a' else 0 

dp = [0] * (n + 1)
ans = [0] * (n + 1)

for i in range(n):
    # 1.第i + 1个字母没有用过
    if dp[i] > dp[i + 1] or (dp[i] == dp[i + 1] and ans[i] < ans[i + 1]):
        dp[i + 1] = dp[i]
        ans[i + 1] = ans[i] 
    
    # 2.第i + 1个字母已经使用过
    if cnt_a[i] >= m: # t是以a开头，所以计算以a开头是否可以匹配
        nv = dp[i] + 1 
        nc = ans[i] + cnt_q[i + m] - cnt_q[i]

        if nv > dp[i + m] or (nv == dp[i + m] and nc < ans[i + m]):
            dp[i + m]  = nv 
            ans[i + m] = nc 

print(ans[n])

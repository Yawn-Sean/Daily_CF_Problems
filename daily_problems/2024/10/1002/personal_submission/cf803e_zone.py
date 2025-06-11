"""
problem url   : https://codeforces.com/problemset/problem/803/E
submission url: https://codeforces.com/contest/803/submission/284018241
"""

n, k = MII() 
a = I()
dp = [[-2] * (2 * k + 1) for _ in range(n + 1)]

dp[0][k] = 0 

dirs = {
    'L': [-1], 
    'W': [1], 
    'D': [0], 
    '?': [-1, 0, 1]
}

mp = {
    -1: 'L', 
    0: 'D', 
    1: 'W'
}

for i in range(n):
    for d in dirs[a[i]]:
        for j in range(1, 2 * k):
            if dp[i][j] != -2:
                dp[i + 1][j + d] = d 

if dp[n][0] == dp[n][-1] == -2: 
    exit(print("NO"))
cur = 0 if dp[n][0] != -2 else 2 * k 

ans = [] 
for i in range(n, 0, -1):
    ans.append(mp[dp[i][cur]])
    cur -= dp[i][cur]
print(''.join(ans[::-1]))

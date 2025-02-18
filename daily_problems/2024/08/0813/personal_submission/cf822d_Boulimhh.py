"""
这道题只想到了每个数应该用最小质数来处理，才能让匹配次数最小化。

dp 还是没有想出来， 得多练 dp 了（哭

每日一赞，羊神思路好清楚。
"""
#python 代码：
t, l, r = map(int, input().split())
n = 5 * 10 ** 6
st = [False] * (n + 1)  
p = [0] * (n + 1)  
dp = [0] * (n  + 1)
mod = 10 ** 9 + 7
for i in range(2, n + 1):
    if st[i] == False: 
        p[i] = i
    
    for j in range(i * i, n + 1, i):
        st[j] = True  
        if p[j] == 0:
            p[j] = i

for i in range(2, n + 1):
    x = p[i]
    dp[i] = (dp[i // x] + i * (x - 1) // 2)

res = 0
for i in range(r, l - 1, -1):
    res = (res * t + dp[i]) % mod

print(res)

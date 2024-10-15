# submission url: https://codeforces.com/contest/340/submission/281700621
mod = 10 ** 9 + 7

n = int(input()) 
a = list(map(int, input().split())) 

cnt1 = cnt2 = 0 
for i, x in enumerate(a, 1):
    if x == -1: 
        if i in a: 
            cnt2 += 1 
        else:
            cnt1 += 1 

dp = [0] * (cnt1 + 1) # cnt1个元素中，恰好有i个元素不在本身位置上的方案个数
dp[0] = 1
for i in range(1, cnt2 + 1):
    dp[0] = (dp[0] * i) % mod

for i in range(1, cnt1 + 1): 
    dp[i] = cnt2 * dp[i - 1] + (i - 1) * dp[i - 1] + (i - 1) * dp[i - 2]
    dp[i] %= mod 
print(dp[-1])

# submission url: https://codeforces.com/contest/735/submission/281305096

n = int(input())
dp = [0] * 100
dp[1], dp[2] = 2, 3 
if n >= 2:
    ans = 1 
if n >= 3:
    ans = 2
for i in range(3, 100):
    dp[i] = dp[i - 1] + dp[i - 2]
    if dp[i] <= n: 
        ans = i
    else:
        break  
print(ans)

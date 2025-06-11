'''
https://codeforces.com/problemset/submission/1016/289854670
1016C
2024/11/4 Y1
1800
DP
'''
# ref
n = int(input())
a1 = list(map(int, input().split()))
a2 = list(map(int, input().split()))

ps1 = [0] * (n + 1)
ps2 = [0] * (n + 1)

for i in range(n):
    ps1[i + 1] = ps1[i] + a1[i]
    ps2[i + 1] = ps2[i] + a2[i]

dp1 = [0] * (n + 1)
dp2 = [0] * (n + 1)

for i in range(n - 1, -1, -1):
    dp1[i] = dp1[i + 1] - (ps1[n] - ps1[i + 1]) - (ps2[n] - ps2[i + 1]) + 2 * i * a1[i] + (2 * n - 1) * a2[i]
    dp2[i] = dp2[i + 1] - (ps1[n] - ps1[i + 1]) - (ps2[n] - ps2[i + 1]) + 2 * i * a2[i] + (2 * n - 1) * a1[i]

ans = dp1[0]
cur = 0

for i in range(n):
    if i & 1:
        cur += 2 * i * a2[i] + (2 * i + 1) * a1[i]
        ans = max(ans, cur + dp1[i + 1])
    else:
        cur += 2 * i * a1[i] + (2 * i + 1) * a2[i]
        ans = max(ans, cur + dp2[i + 1])

print(ans)
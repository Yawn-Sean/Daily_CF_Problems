'''
https://codeforces.com/problemset/submission/319/294383156
CF319A
2024/11/30 Y1
1600
math
'''
# ref
s = input()
n = len(s)

MOD = 1000000007
ans = 0

c = 1
for i in range(n - 1, -1, -1):
    ans = (ans + ans) % MOD
    if s[i] != '0':
        ans = (ans + c * c) % MOD
    c = (c + c) % MOD

print(ans)
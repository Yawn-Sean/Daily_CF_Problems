'''
https://codeforces.com/problemset/submission/337/292885810
337C
20241123 Y1
1600
math
'''
# ref
n, m, k = map(int, input().split())
MOD = 1000000009

x = min(m, n - n // k)
y = m - x

x -= (k - 1) * y
print((k * (pow(2, y + 1, MOD) - 2) + x) % MOD)
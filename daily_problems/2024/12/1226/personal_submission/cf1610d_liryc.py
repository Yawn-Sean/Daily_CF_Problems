'''
https://codeforces.com/problemset/submission/1610/298484019
1610D
2024/12/26 Y2
2000
math
'''
# ref, 裴蜀定理(Bezout Theorem)
n = int(input())
a = list(map(int, input().split()))

mod = 10 ** 9 + 7

cnt = [0] * 30
for num in a:
    cnt[(num & -num).bit_length() - 1] += 1

ans = pow(2, n, mod) - pow(2, n - cnt[0], mod)
if ans < 0: ans += mod

resid = n - cnt[0]
for i in range(1, 30):
    resid -= cnt[i]
    if cnt[i] >= 2:
        ans += (pow(2, cnt[i] - 1, mod) - 1) * pow(2, resid, mod) % mod
        if ans >= mod:
            ans -= mod

print(ans)
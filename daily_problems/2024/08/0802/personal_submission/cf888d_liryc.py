'''
https://codeforces.com/contest/888/submission/273966972
CF888D
2024/8/2 Y1
1600
排列组合
'''

from math import comb

n, k = map(int, input().split())
ans = 1
if k >= 2:
    ans += comb(n, 2)
if k >= 3:
    ans += comb(n, 3) * 2
if k == 4:
    ans += comb(n, 4) * 9
print(ans)

    
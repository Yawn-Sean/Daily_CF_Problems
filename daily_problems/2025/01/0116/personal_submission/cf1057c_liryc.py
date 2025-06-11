'''
https://codeforces.com/problemset/submission/1057/301180998
1057C
2025/1/16 Y2
2000
DP
'''
# DPDFS: dp[i][r][lb] : 当前位置i，还剩r颗糖，下次吃的大于lb

from functools import cache
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, s, k = map(int, input().split())
    s -= 1
    a = list(map(int, input().split()))
    colors = input()
    return n, s, k, a, colors

rmin = lambda a, b: b if a == -1 or b < a else a

def solve(n, s, k, a, colors):
    @cache
    def dpdfs(i, r, lb):
        global rmin
        nonlocal n, a, colors
        ans = -1
        for j in range(n):
            if colors[j] != colors[i] and a[j] > lb:
                if a[j] < r:
                    res = dpdfs(j, r - a[j], a[j])
                    if res >= 0:
                        ans = rmin(ans, abs(i - j) + res)
                else:
                    ans = rmin(ans, abs(i - j))
        return ans
    min_time = -1
    for i in range(n):
        if a[i] < k:
            res = dpdfs(i, k - a[i], a[i])
            if res >= 0:
                min_time = rmin(min_time, abs(s - i) + res)
        else:
            min_time = rmin(min_time, abs(s - i))
    return min_time

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)
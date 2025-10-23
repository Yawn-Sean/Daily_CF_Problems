"""
首先，可能需要一个背包
算一下从 m_min 到 m_max，哪些质量可以被拼凑出来
进一步，我们关心这个质量能被拼出来几次
不妨设 dp[i][j] 表示从前 i 种零件里选，拼凑出质量 j，至多能拼凑出 j 多少次
dp[i][j] = dp[i - 1][j]
dp[i][j] = max(min(dp[i - 1][j - cnt * m[i]], c[i] // cnt)), cnt >= 1
最后看 dp[n][m_min] 到 dp[n][m_max] 的最大值就好了
需要枚举 i, j, cnt，复杂度 O(nm^2)，无法通过本题
注意到答案具有单调性，考虑二分
检查时，相当于每个物品可以用 c[i] // ans 次，使用多重背包看能否凑出 m_min 和 m_max 之间的数即可
"""

import sys

input = lambda: sys.stdin.readline()

n, m_min, m_max = map(int, input().split())

m = [0]
c = [0]

for i in range(n):
    mm, cc = map(int, input().split())
    m.append(mm)
    c.append(cc)

def check(ans):
    divided_m = [0]
    for i in range(1, n + 1):
        cnt = c[i] // ans
        left_cnt = cnt
        for j in range(cnt):
            if left_cnt >= (1 << j):
                divided_m.append((1 << j) * m[i])
                left_cnt -= (1 << j)
            else:
                break
        if left_cnt > 0:
            divided_m.append(left_cnt * m[i])

    cnt = len(divided_m) - 1
    dp = [False for _ in range(m_max + 1)]
    INF = int(1e15)
    dp[0] = True

    for i in range(1, cnt + 1):
        for j in range(m_max, -1, -1):
            if j - divided_m[i] >= 0:
                dp[j] = (dp[j] or dp[j - divided_m[i]])

    res = False
    for j in range(m_min, m_max + 1):
        res = (res or dp[j])
    return res

l, r = 0, int(1e6)
while l + 1 < r:
    mid = (l + r) // 2
    if check(mid):
        l = mid
    else:
        r = mid

res = l
if check(r):
    res = r
print(res)

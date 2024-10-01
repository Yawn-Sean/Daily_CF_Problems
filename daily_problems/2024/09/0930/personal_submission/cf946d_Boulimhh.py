"""
思路: 逃课只有逃最开始的课和最后的课才有意义， 逃中间的课没影响，不如不逃。

统计每节课的时间点， 并计算逃 j 节课的情况下， 前边逃 x 节， 后边逃 j - x节的时长， 求其时长最小值。

再初始化背包， 探讨逃 j 节课之后， 需要用时的最小值。

"""
#python代码：
n, m, k = map(int, input().split())
a = [[] for i in range(n)]
for i in range(n):
    s = input()
    for j in range(m):
        if s[j] == '1': a[i].append(j)

w = [([0] * (k + 1)) for i in range(n)]
for i in range(n):
    if len(a[i]) == 0: continue
    for j in range(k + 1):
        if len(a[i]) <= j: continue
        w[i][j] = a[i][-1] - a[i][0] + 1
        for x in range(j + 1):
            y = len(a[i]) - 1 - (j - x) # 去掉后边部分的下标
            if y >= x:  #   后边去掉之后的下标大于等于前边去掉部分的下标
                w[i][j] = min(w[i][j], a[i][y] - a[i][x] + 1)

dp = [[n * m] * (k + 1) for i in range(n)]
for j in range(k + 1):
    dp[0][j] = w[0][j]

for i in range(1, n):
    for j in range(k + 1):
        for l in range(j + 1):
            dp[i][j] = min(dp[i][j], w[i][l] + dp[i - 1][j - l])
print(dp[-1][-1])

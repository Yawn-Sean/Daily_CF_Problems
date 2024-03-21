import sys
input = lambda: sys.stdin.readline().strip()

# 假设 a < b < c
#   排列为 a b c 时，|a - b| + |b - c| = c - b + b - a = c - a
#   排列为 a c b 时，|a - c| + |c - b| = c - a + c - b > c - a
# 让数字保持顺序排列可以保持差值和最小
# 根据题意，需要计算 Ai+k - Ai 的和，可以理解为存在k个子序列：
#   A0 Ak A2k A3k ...
#   A1 Ak+1 A2k+1 A3k+1 ...
# 仅同一序列内的相邻数字会影响计算结果，为保持总和最小，我们保持大小相邻的数字在同一组内，即对原数组排序后按顺序分组
# 这里存在一个组的大小不均的问题，比如共有10个数，k=3，则子数组的长度应为 4 3 3
# 总计应有 n % k 个数组长度为 n // k + 1，称为长数组，k - n % k 个数组长度为 n // k，称为短数组
# 定义 dp[i][j] 为从左到右选择，已选择 i 个数组，其中 j 个长数组时，最小的差值和，其中 dp[0][0] = 0
# 给定 i j，我们可以确定末位元素的编号为： j * (n // k + 1) + (i - j) * n // k
# 通过选择最后一个数组的长度，我们可以转移到前置状态

n, k = map(int, input().split())
nums = list(sorted(map(int, input().split())))
size = n // k

dp = [[0] * (n % k + 1) for _ in range(k + 1)]
for i in range(1, k + 1):
    dp[i][0] = dp[i - 1][0] + nums[i * size - 1] - nums[(i - 1) * size]
for i in range(1, k + 1):
    for j in range(1, min(i, n % k) + 1):
        dp[i][j] = dp[i-1][j-1] + nums[(j - 1) * (size + 1) + (i - j) * size + size] - nums[(j - 1) * (size + 1) + (i - j) * size]
        if j < i:
            dp[i][j] = min(dp[i][j], dp[i-1][j] + nums[j * (size + 1) + (i - 1 - j) * size + size - 1] - nums[j * (size + 1) + (i - 1 - j) * size])
print(dp[-1][-1])

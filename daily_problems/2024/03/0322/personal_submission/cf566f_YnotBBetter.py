import sys
input = lambda: sys.stdin.readline().strip()

# 当两个数字构成整除关系时，这两个数字之间可以连边，目标是让结果集中的所有数字两两连边
# 假设有 a < b < c，则一定有 b 是 a 的倍数，且 c 是 b 的倍数
# 如果此时发现了一个 d 是 c 的倍数，则 d 一定同时是 a 和 b 的倍数，可以加入集合
# 我们从小到大枚举元素，用小元素的结果更新大元素的结果

n = int(input())
nums = [0] * (10 ** 6 + 1)
for v in input().split():
    nums[int(v)] += 1

ans = 0
dp = [1] * (10 ** 6 + 1)
for i in range(10 ** 6 + 1):
    if nums[i] == 0:
        continue
    ans = max(ans, dp[i])
    tmp = i * 2
    while tmp < 10 ** 6 + 1:
        dp[tmp] = max(dp[tmp], dp[i] + 1)
        tmp += i
print(ans)



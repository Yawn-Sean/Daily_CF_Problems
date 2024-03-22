import sys

import math

input = lambda: sys.stdin.readline().strip()

# 1 <= n <= 30, 1 <= target <= 10 ** 9
# 看起来像是背包问题，通常可以定义 dp[i][j] 为使用前 i + 1 种硬币获得总价值 j 的最少代价
# 但本题中 j 的范围非常大，直接套用这个思路会超时
# 本题的特点是，瓶子容量的增长是指数性的，总容量不需要严格等于目标值
# （羊）由于瓶子容量存在倍数关系，大容量瓶子总能替换成两个更小容量的瓶子，因此大瓶子的性价比一定是大于等于小瓶子的
# 那么显然在容量允许的情况下，我们应当优先选择性价比最高的瓶子（即从大瓶子开始向小瓶子遍历）
# 当遍历到第 i 个瓶子时，我们先尽可能选择这个瓶子，直到瓶子容量已经超出目标值
# 此时要么再选择一个 i 号瓶子，要么使用更小的瓶子，就看哪种情况的开销更小

def main():
    n, target = map(int, input().split())
    costs = list(map(int, input().split()))
    for i in range(1, n):
        costs[i] = min(costs[i], costs[i - 1] << 1)

    ans = math.inf
    cur = 0
    for i in reversed(range(n)):
        cnt = target // (1 << i)
        target -= cnt * (1 << i)
        cur += cnt * costs[i]
        if target == 0:
            print(min(ans, cur))
            return
        ans = min(ans, cur + costs[i])
    print(ans)


main()

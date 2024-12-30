import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 如果是给定一个集合查询的话好做：就是求一个最大值，然后分类讨论，但是有2^n个集合，该怎么处理？
# 想不到是dp，也想不到优化，直接看村长题解了qwq

mod = 998244353
n = II()
nums = LMII()
nums.sort() # 排序后直接可以进行状态转移

dp = [0] * 5001 # 总球数不超过5000
dp[0] = 1 # dp[x]当前总数为x的方案数目

cur_sum = 0
ans = 0
for num in nums:
    for i in range(cur_sum, -1, -1):
        if dp[i]:
            ans = (ans + dp[i] * max((i + num + 1) // 2, num)) % mod
            dp[i + num] = (dp[i + num] + dp[i]) % mod
    cur_sum += num

print(ans)
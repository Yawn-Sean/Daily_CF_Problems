"""
思路： 计算数组纯递增是什么样， 纯递减是什么样

再依次按照递增递减去计算需要补充的差值。

最后枚举每个位置，求最小值即可。

"""
#python代码：
n = int(input())
nums = list(map(int, input().split()))

pre= [0] * n
suf = [0] * n
suf_d = [0] * n
pre_d = [0] * n
for i in range(n - 1):
    pre[i + 1] = max(pre[i] + 1, nums[i])
    pre_d[i + 1] = pre_d[i] + pre[i + 1] - nums[i]
for i in range(n - 1, 0, -1):
    suf[i - 1] = max(suf[i] + 1, nums[i])
    suf_d[i - 1] = suf_d[i] + suf[i - 1] - nums[i]

ans = 10 ** 15
for i in range(n):
    ans = min(ans, pre_d[i] + suf_d[i] + max(max(pre[i], suf[i])+ 1 - nums[i], 0))
print(ans)

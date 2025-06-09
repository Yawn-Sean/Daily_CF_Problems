"""
把高度都换为从0开始， 作一个离散化

注意到可以划分为块， 一定是 块内数字排序后 等于 数组排序后对应位置的数字

这个点可以用前缀和实现是否划分为块， 因为离散化后一定数字不同

还是羊神的方法简洁， 直接相减判断是否为 0
"""
# python代码：

# 满足前 i 个数 都是 前 i 个最小的数 的最大块数
n = int(input())
h = list(map(int, input().split()))

# 离散化后排序，做一个前缀和
p = [i for i in range(n)]
s = list(accumulate(p, initial = 0))
p.sort(lambda x: h[x])

res = 0
l = sum_s = 0
for i in range(n):
    sum_s += p[i]
    if sum_s == s[i + 1] - s[l]:
        res += 1
        sum_s = 0
        l = i + 1
print(res)

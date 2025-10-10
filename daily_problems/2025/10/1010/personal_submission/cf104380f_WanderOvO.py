"""
有没有办法，能让最大的 R - L + 1 个数都在 [L, R] 下标范围内？
最后一个数的下标要么是 1 要么是 n，假如它是最大的数，且 1, n 都不属于 [L, R]
则这个数必然不能贡献进来，所以无脑选前 R - L + 1 大是不行的
我们先看看能不能把前 R - L + 1 大的数放在一起吧
这个是容易的，我们可以钦定遇到这种数就往右边塞，否则往左边塞，这样就可以让它们连续
L 和 R 是预先给定的，这意味着什么？
到底哪些数能用？
如果 L = 1，则我们只需要遇到想要的元素时再左插就好了，一定能做到
R = n 也是类似的，想要时右插，否则左插
1 < L <= R < n 时呢？如果想遇到想要的就左插，则插完之后还得再垫 L - 1 个
如果遇到想要的就右插，则插完之后右边也得垫几个
我们能否去枚举 a 中从哪个后缀开始，元素全都不是想要的？
假设后 cnt 个元素都不想要，则前 n - cnt 个元素能否选最大的 R - L + 1 个呢？
首先，如果要垫左边，则需要 L - 1 个元素，如果要垫右边，则需要 n - R 个元素
后边的垫材够不够呢？
我觉得我们要看这样一个事情，枚举最后 cnt 个元素强制不选
然后看前 n - cnt 个元素把前 R - L + 1 大连在一起后，能不能用后边的调整到 [L, R] 区间里
这个时候，我们就要分别看如果遇到想要的元素就右插，是否可行
以及如果遇到想要的元素就左插，是否可行
实现时，我们可以先把前 R - L + 1 个元素塞到小根堆里面
然后，不断看能否让堆中最小元素变得更大，之后看放左边和放右边能不能调整好
"""
import heapq

n, L, R = map(int, input().split())
a = list(map(int, input().split()))

b = []
sum = 0
for i in range(R - L + 1):
    heapq.heappush(b, a[i])
    sum += a[i]

res = sum
for i in range(R - L + 1, n):
    mn = heapq.heappop(b)
    if mn < a[i]:
        heapq.heappush(b, a[i])
        sum -= mn
        sum += a[i]
    else:
        heapq.heappush(b, mn)
    other = i + 1 - (R - L + 1)
    if other <= L - 1:
        left_cnt = n - 1 - i
        if other + left_cnt >= L - 1:
            res = max(res, sum)
    else:
        left_cnt = n - 1 - i
        if left_cnt >= L - 1:
            res = max(res, sum)
print(res)

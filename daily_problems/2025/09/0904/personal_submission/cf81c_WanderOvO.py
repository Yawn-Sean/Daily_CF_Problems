"""
平均值是浮点数
sum(x) / x + sum(y) / y
通分一下：(y * sum(x) + x * sum(y)) / (x * y) 最大
其实就是最大化 y * sum(x) + x * sum(y)
总的 sum 我们是知道的，相当于最大化分子 y * sum(x) + x * (sum(n) - sum(x))
= (y - x) * sum(x) + x * sum(n)
如果 y > x，则需要最大化 sum(x)，y < x 则需要最小化 sum(x)
y = x 则怎么分都无所谓，输出排序后的结果就好
最大化 sum(x) 其实就是把最大的 x 个数放到第一个数列里，且按照从小到大放
最小化 sum(x) 其实就是把最小的 x 个数放到第一个数列里，且按照从小到大放
y = x 时，前 x 个分到 1，后 y 个分到 2 即可
"""
import sys

input = lambda: sys.stdin.readline().strip()

n = int(input())
a, b = map(int, input().split())
t = list(map(int, input().split()))
origin_t = [t[i] for i in range(n)]
t.sort()
res = [0 for _ in range(n)]
if b > a:
    cnt = [0 for _ in range(10)]
    for i in range(n - 1, n - a - 1, -1):
        cnt[t[i]] += 1
    for i in range(n):
        if cnt[origin_t[i]] > 0:
            res[i] = 1
            cnt[origin_t[i]] -= 1
        else:
            res[i] = 2
elif b < a:
    cnt = [0 for _ in range(10)]
    for i in range(a):
        cnt[t[i]] += 1
    for i in range(n):
        if cnt[origin_t[i]] > 0:
            res[i] = 1
            cnt[origin_t[i]] -= 1
        else:
            res[i] = 2
else:
    for i in range(a):
        res[i] = 1
    for i in range(a, n):
        res[i] = 2

print(*res)

"""
如果 a[i] 是极大值，那么 a[i + 1] 就得是极小值
所以其实只有两大种情况
- 奇数下标是极大值，偶数下标是极小值
- 奇数下标是极小值，偶数下标是极大值
我们把这两种情况分别计算一下就好了，我们挑一种仔细分析一下
考虑奇数下标极大，偶数下标极小
则枚举到某个下标 i 时，倘若它应该是极大，并且已经符合题意了，就无需改动
否则，我们是增加现在这个，还是缩小下一个呢？
由于下一个必须是极小，所以缩小下一个是更优的
"""
import sys

input = lambda: sys.stdin.readline().strip()

n = int(input())
a = [0] + list(map(int, input().split()))
b = []
for i in range(len(a)):
    b.append(a[i])

res1, res2 = 0, 0
# 奇数极大
for i in range(1, n):
    if i % 2 == 1:
        if a[i] <= a[i + 1]:
            c = a[i + 1] - a[i] + 1
            res1 += c
            a[i + 1] = a[i] - 1
    else:
        if a[i] >= a[i + 1]:
            c = a[i] - a[i + 1] + 1
            res1 += c
            a[i + 1] = a[i] + 1

for i in range(len(b)):
    a[i] = b[i]

# 偶数极大
for i in range(1, n):
    if i % 2 == 0:
        if a[i] <= a[i + 1]:
            c = a[i + 1] - a[i] + 1
            res2 += c
            a[i + 1] = a[i] - 1
    else:
        if a[i] >= a[i + 1]:
            c = a[i] - a[i + 1] + 1
            res2 += c
            a[i + 1] = a[i] + 1

print(min(res1, res2))

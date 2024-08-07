"""
思路：
看样例得知所有操作只针对数组里的一个数，所以可以把所有操作变成一个操作。
 × × × 尝试把操作给数组最大值，结果惨遭一发wa  × × ×
看了羊神题解，对某个数操作后，可以通过前后缀减少复杂度
这样的话，解题思路明朗了，分别尝试对每个数进行这次操作，取max值就好。
"""
Python代码:
n, k, x = map(int, input().split())
a = list(map(int, input().split()))
val = x ** k
pre, suf = [0]*n, [0]*n

for i in range(n - 1):
    pre[i + 1] = a[i] | pre[i]
for i in range(n - 1, 0, -1):
    suf[i - 1] = a[i] | suf[i]

res = 0
for i in range(n):
    res = max(res, (a[i] * val) | pre[i] | suf[i])
print(res)

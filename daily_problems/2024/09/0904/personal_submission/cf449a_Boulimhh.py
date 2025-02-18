"""
思路：分情况讨论，小矩形的最大值。

于是有切的多， 短边切， 长边切， 二者都切取最大。

"""
#python代码：
n, m, k = map(int, input().split())
n, m = max(n,m), min(n,m)
if n + m - 2 < k:
    print(-1)
elif n - 1 < k:
    print(m // (k - n + 2))
elif m - 1 < k:
    print(n // (k + 1) * m)
else:
    print(max(n // (k + 1) * m, m // (k + 1) * n))

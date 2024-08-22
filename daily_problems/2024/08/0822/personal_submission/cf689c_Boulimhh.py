"""
思路： 求满足条件的最小值。

数学题， 推导一下。 a * k ^ 3 <= n, 所以等比数列的 q 最大可以取到 n ^ (1/ 3)， 即 k 最大可以取到 n ^ (1/ 3)。

那么怎么统计满足条件的个数呢， 由上式可得，  a = n // (k ^ 3) ， 所以 a 可以取到 1 ~ n // (k ^ 3)。

在 k 固定的情况下， a 有 n // (k ^ 3) 个满足条件的数。 

在 k 满足 2 ~  n ^ (1/ 3) 的情况下，  对 a 的个数加和， 就可以求得在 n 的情况下， 是否恰好有 m  个组合 。 

由于 m  的范围为 10 ** 15 , 太大了， 二分启动！！！

这里借鉴了羊神的 8 * m 的上界， 判断上界确实还不太熟练。。。。

"""

# python代码：
def check(n):
    max_k = int(n ** 0.34)
    c = 0
    for k in range(max_k, 1, -1):
        c += n // (k ** 3)
    return c

m = int(input())
l, r = 0, 8 * m

while l < r:
    mid = l + r >> 1
    if check(mid) >= m:
        r = mid
    else:
        l = mid + 1
print(l if check(l) == m else -1)

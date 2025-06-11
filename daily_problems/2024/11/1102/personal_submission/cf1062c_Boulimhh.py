"""
思路：先推了一遍样例，最后总结出来规律
a       b                c             d
a       b + a            c + a         d + a
a       b + d + 2a       c + d + 2a    d + a
a       b + 2d + c + 4a  c + d + 2a    d + a = 8a + 4d + 2c + d     = 2^3a + 2^2d +2^1c + 2^0d
也就是 2 ** n - 1， 这里的 n 是区间内 1 的个数。

如果后边都是0, 那就会直接翻倍，比如 10000， 变成1 1111 = 11 222 - 112 44 -  1124 8

每一项在原来基础上乘以2 用等比求和 a1 *(1-q**n) / (1 - q)， 这里q是2 化简有 a1 *(2 ** n - 1)

其中 a1 是连续 1 求出来的等比总和， 那么两个公式可以结合，所求结果为 (2 ** (cnt1) - 1) * (2 ** cnt0)

这里我只用 前缀和 统计每个区间有多少个1 再算有几个0，带入公式。没有预处理连续1 和连续0 的情况。 用上了python的pow，还真阔以
"""
#python代码：
MOD = 10 ** 9 + 7
n, q = map(int, input().split())
s = input()
pre = [0]
for c in s:
    if c == '1':
        pre.append(pre[-1] + 1)
    else:
        pre.append(pre[-1])
for _ in range(q):
    l, r = map(int, input().split())
    cnt1 = pre[r] - pre[l - 1]
    cnt0 = r - l + 1 - cnt1
    res = (pow(2, cnt1, MOD) - 1) * pow(2, cnt0, MOD)
    print(res % MOD)

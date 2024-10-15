"""
哇，酣畅淋漓的数学公式题。
思路：
先推理k， k可以是1 - a, 等差数列求和搞
再推理x mod b 为多少，x mod b 可以为 1 - b - 1. 当mod为 0，则不存在. 可以等差数列搞

解题过程:
先暴力二重循环，发现过不去（没看范围
再优化为 1 重循环，还是tle
直接整合出一个数学公式 O(1)直接ac
"""
#Python代码:

mod = int(10 ** 9 + 7)
a, b = map(int, input().split())
p = (b - 1) * b // 2
q = a * (a + 1) // 2
ans = (p * q * b + a * p) % mod
print(ans)

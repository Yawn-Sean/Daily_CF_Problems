from array import array
from itertools import accumulate

MOD = 998244353
n, D = map(int, input().split())

m = n // 2
p, _r = divmod(m + D, 2)
if _r or p < 0 or (m - p) < 0:
    exit(print(0))

pow2 = array('i', accumulate(
    range(1, m + 1),
    lambda pre, _: pre * 2 % MOD,
    initial=1
))
pow2_inv = array('i', [1] * (m + 1))
pow2_inv[-1] = pow(pow2[-1], -1, MOD)
for i in range(m - 1, 0, -1):
    pow2_inv[i] = pow2_inv[i + 1] * 2 % MOD

fc = array('i', accumulate(
    range(1, n + 1),
    lambda pre, x: pre * x % MOD,
    initial=1
))
fc_inv = array('i', [1] * (n + 1))
fc_inv[-1] = pow(fc[-1], -1, MOD)
for i in range(n - 1, 1, -1):
    fc_inv[i] = fc_inv[i + 1] * (i + 1) % MOD


def C(x: int, y: int) -> int:
    return fc[x] * fc_inv[y] * fc_inv[x - y] % MOD


ans = 0
for i in range(m + 1):
    x = C(m, i) * fc[n - i] * pow2_inv[m - i] % MOD
    ans += (-x) if i & 1 else x
print(ans * C(m, p) % MOD)


"""
首先 D 是一个很诈骗的值
b 相当于是, swap(a[pos[x]], a[pos[x+1]]) for x in range(0, n, 2)
因为交换的元素的值只差 1, 所以逆序对改变的个数 D, 只跟他们 pos 的前后关系有关
设有
- p 对 pos[x]<pos[x+1]
- q 对 pos[x]>pos[x+1]
那么
- p+q == n // 2
- p-q == D
所以就可以求出 p 和 q
令  m := (n+1) // 2
把这些数两两配对(有可能单独剩一个, 算在 m 里), 先强制规定 x 在 (x+1) 前面
- m 个元素的排列, m!
- (n-m) 对中, 对选出 p 对指定前后关系, C(n-m, p)
- (n-m) 对中, pos 较大的数如何选择位置
    - 第一个数有 (m-1) 个位置
    - 第二个数有 (m-1) 个位置
    - 多余的数不管
    - 多余的数后面的数, 每个都有 (m-2) 个位置
可以考虑枚举多余的数的位置, 然后进行加法
---
前面的步骤都对, 最后一步插入的时候错了, 需要使用容斥
因为插入一个数后, 后面的数能用的槽位会变, 简单的乘方不行
"""

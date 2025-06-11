"""
思路： 一看n和k这么大，直接推公式

3 2
5 6
9 10 11 12 = (1 / 2 **  k) * (n * 2 **  k + n * 2 **  k - 1 +... + n * 2 **  k - 2 **  k + 1) = 求和公式: 2 **  k(n * 2 ** (k + 1) - 2 **  k + 1)/2
概率 1 / 2 ** k， 直接概率乘以2 , 变成 2 / 2 **  k
合并一下变成 (2 / 2 **  k ) * 2 **  k * (2 **(k + 1) * n - 2**  k - 1) / 2  = 2 ** (k + 1) * n- 2 **  k +  1 = 2 ** k *(2 * n - 1) + 1

嘿嘿，一提交喜提mle ，上了个快速幂的板子。过了。

才发现python自带快速幂的函数pow， 血亏！！！（不过用函数好像没手写板子跑得快，不知道怎么回事）
"""
#python代码：
MOD = 10 ** 9 + 7
n, k = map(int, input().split())
if n == 0:
    print(0)
    exit()
def qmi(a, b, p):
    res = 1 % p
    while(b):
        if b & 1: res = res * a % p
        a = a * a % p
        b >>= 1
    return res
n = (2 * n - 1) % MOD
print((n * qmi(2, k, MOD) + 1) % MOD)

import sys
input = lambda: sys.stdin.readline().strip()
MOD = 10 ** 9 + 7

'''
    令根结点深度为0，答案就是所有深度为奇数的点的数量。
    方案：将所有深度为奇数的点和它的父亲连边。
    由于每条边连接的两个点的深度奇偶性不同，我们取到了所有深度为奇数的点，因此是最大边集。

    f[i][j]: i个左括号，j个左括号的序列个数（要求i >= j)
    答案为sum(f[i][j])，其中i + j & 1
'''

n = int(input())
f = [[0] * (n + 1) for _ in range(n + 1)]
f[0][0] = 1
res = 0
for i in range(1, n + 1):
    for j in range(i + 1):
        f[i][j] = (f[i - 1][j] + f[i][j - 1]) % MOD
        if i + j & 1:
            res = (res + f[i][j]) % MOD
print(res)





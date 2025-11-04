"""
c(1, 1) ^ ... ^ c(n, 1)
c(2, 2) ^ ... ^ c(n, 2)
c(i, i) ^ ... ^ c(n, i)
c(n, n)
交换一下异或顺序吧
c(1, 1)
c(2, 1) ^ c(2, 2)
c(3, 1) ^ c(3, 2) ^ c(3, 3)
c(n, 1) ^ ... ^ c(n, n)
注意到 c(i, j) = c(i, i - j)，所以能消掉很多
最终的计算式应该是
c(1, 1)
c(2, 1) ^ c(2, 2)
c(3, 3)
c(4, 2) ^ c(4, 4)
c(5, 5)
c(6, 3) ^ c(6, 6)
也就是说，对于每个 i，都会贡献 c(i, i)
对于 i 为偶数时，还会贡献 c(i, i / 2)
我们可以预处理出前缀异或和，这就是答案了
"""

import sys

input = lambda: sys.stdin.readline().rstrip()
mod = 998244353
N = 10 ** 6 + 10
res = [0 for _ in range(N)]
fact = [1 for _ in range(N)]
invfact = [1 for _ in range(N)]
for i in range(1, N):
    fact[i] = fact[i - 1] * i % mod
    invfact[i] = pow(fact[i], -1, mod)
res[1] = 1

def C(n, m):
    return fact[n] * invfact[m] % mod * invfact[n - m] % mod

for i in range(2, N):
    res[i] = res[i - 1] ^ 1
    if i % 2 == 0:
        res[i] ^= C(i, i // 2)

T = int(input())
ans = []
while T > 0:
    T -= 1
    n = int(input())
    ans.append(res[n])
print("\n".join(map(str, ans)))

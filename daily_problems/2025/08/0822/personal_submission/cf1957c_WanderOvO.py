"""
每行每列只能有一个车
首先我们应该找出来还有哪些行哪些列没有放棋子
然后考虑对行列进行配对，一个行配一个列，一定是合理的
配好对之后，对于 r != c 的对，其可以交换黑白顺序，从而又给方案数 * 2
由于是对称放的，所以剩下的行和剩下的列的编号是相同的
假设剩下 cnt 个 id，考虑枚举有多少对是自己和自己配的
假设是 i 对，则先选出这 i 对，C(cnt, i)
然后对于剩下的 cnt - i 个数，我们强制他们不能自己配对，所以 cnt - i 必须是偶数，要求一个 cnt - i 个数两两匹配的匹配数
如何求 i 个数两两匹配的匹配数？直接 C(cnt - i, 2) * C(cnt - i - 2, 2)...乘起来，去掉顺序 ((cnt - i) // 2)! 即可
最后，再把配对部分内部交换的方案算进去，乘以 2^(cnt - i)
"""
import sys

N = int(3e5 + 10)
mod = int(1e9 + 7)

pow2 = [1 for _ in range(N)]
for i in range(1, N):
    pow2[i] = pow2[i - 1] * 2 % mod

fact = [1 for _ in range(N)]
for i in range(1, N):
    fact[i] = fact[i - 1] * i % mod

invfact = [1 for _ in range(N)]
for i in range(N):
    invfact[i] = pow(fact[i], -1, mod)

dp = [0 for _ in range(N)]
dp[0] = 1
for i in range(2, N, 2):
    dp[i] = dp[i - 2] * fact[i] * invfact[i - 2] * invfact[2] % mod

input = lambda: sys.stdin.readline().rstrip()
T = int(input())
while T > 0:
    T -= 1
    n, k = map(int, input().split())
    vis = [False for _ in range(n + 1)]
    for i in range(k):
        r, c = map(int, input().split())
        vis[c] = True
        vis[r] = True
    cnt = 0
    for i in range(1, n + 1):
        if not vis[i]:
            cnt += 1
    if cnt == 0:
        print(1)
        continue

    res = 0
    for i in range(cnt + 1):
        if (cnt - i) % 2 == 0:
            res += ((fact[cnt] * invfact[i] * invfact[cnt - i]) % mod * dp[cnt - i] * invfact[(cnt - i) // 2] % mod) * pow2[(cnt - i) // 2]
            res %= mod
    print(res)

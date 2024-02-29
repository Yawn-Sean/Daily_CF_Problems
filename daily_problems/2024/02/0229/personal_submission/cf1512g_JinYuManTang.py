import sys
input = lambda: sys.stdin.readline().strip()
N = int(1e7 + 50)

'''
    将n分解质因数 n = pow(p1, c1) * pow(p2, c2) * …… * pow(pm, cm)
    d(n) = (1 + p1 + p1**2 + …… + p1**c1) (1 + p2 + p2**2 + …… + p2**c2) ……
    对于互质的a和b，显然d(ab) = d(a)d(b)
    
    筛法求约数和 https://oi-wiki.org/math/number-theory/sieve/
    f[i]: i的因数和
    g[i]: i的最小质因子p的 pow(p, 0) + pow(p, 1) + pow(p, 2) + …… + pow(p, c)
'''

primes = []
is_prime = [True] * N
f, g = [0] * N, [0] * N
f[1] = g[1] = 1
for i in range(2, N):
    if is_prime[i]:
        primes.append(i)
        f[i] = i + 1
        g[i] = i + 1
    for p in primes:
        if i * p >= N:
            break
        is_prime[i * p] = False
        if i % p == 0:  # p是i的最小质因子
            g[i * p] = g[i] * p + 1
            f[i * p] = f[i] // g[i] * g[i * p]
            break
        # 此时i和p互质，p是i * p的最小质因子
        f[i * p] = f[i] * f[p]
        g[i * p] = 1 + p

res = [-1] * N
for i in range(1, N):
    if f[i] <= N and res[f[i]] == -1:
        res[f[i]] = i

def solve():
    c = int(input())
    print(res[c])

for _ in range(int(input())):
    solve()
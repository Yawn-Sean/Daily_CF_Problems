'''
https://codeforces.com/gym/104822/submission/342438144
'''
# primes, factors
from collections import Counter
from sys import stdin
input = lambda: stdin.readline().strip()
pmin = lambda x, y: x if y < 0 or x >= 0 and x <= y else y

MAXN = int((10 ** 9 + 1000) ** 0.5) + 1
prime_factors = []
prime_set = []
def initPrimes():
    global prime_factors, prime_set, MAXN
    prime_factors = list(range(MAXN + 1))
    limit = int((MAXN) ** 0.5) + 1
    for i in range(2, limit):
        if prime_factors[i] == i:
            prime_set.append(i)
            for j in range(i * i, MAXN + 1, i):
                if prime_factors[j] == j:
                    prime_factors[j] = i
    for i in range(limit, MAXN + 1):
        if prime_factors[i] == i:
            prime_set.append(i)

def solve(n: int) -> int:
    global prime_set

    m = n
    cn = Counter()
    for p in prime_set:
        if p * p > m: 
            break
        d, v = divmod(m, p)
        while v == 0:
            cn[p] += 1
            m = d
            d, v = divmod(m, p)

    if m > 1:
        cn[m] = 1
    
    fa = [1]
    
    for x, c in cn.items():
        k = len(fa)
        for i in range(c * k):
            fa.append(fa[i] * x)

    fa.sort()

    i, j = 0, len(fa) - 1
    ans = -1
    while i <= j:
        ans = pmin(ans, fa[i + 1] * fa[j])
        i, j = i + 1, j - 1

    return ans - n

if __name__ == '__main__':
    initPrimes()
    for _ in range(int(input())):
        n = int(input())
        ans = solve(n)
        print(ans)

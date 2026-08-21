'''
2026/08/21 Y1
1500
Math, factors
'''
import sys
from collections import Counter

from math import gcd
input = lambda: sys.stdin.readline().strip()
pmax = lambda x, y: y if y > x else x
pmin = lambda x, y: y if y < x else x
# pmin = lambda x, y: x if y < 0 or x >= 0 and x <= y else y

## 质数筛 - prime_factors[x]表示x的最小因子，x是质数 iff prime_factors[x] == x
## 更新20260514: 新增欧拉函数初始化phi[n]
MAXN = int((10 ** 9 + 1000) ** 0.5) + 1
prime_factors = []
prime_set = []
def initPrimes():
    global prime_factors, prime_set
    prime_factors = list(range(MAXN + 1))
    phi = list(range(MAXN + 1))
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

# 分解质因数，例如 (20) = {2:2, 5:1}
# 本方法适用于 n <= 1e9 的情况
def prime_elements(n: int):
    for p in prime_set:
        if p * p > n: 
            break
        c = 0
        d, v = divmod(n, p)
        while v == 0:
            c += 1
            n = d
            d, v = divmod(n, p)
        if c:
            yield p, c
    if n > 1:
        yield n, 1

# 获取所有因子(并从小到大排序），例如(24) = [1, 2, 3, 4, 6, 8, 12, 24]
# 例题：[GYM104822I(20251007Y1)](https://codeforces.com/gym/104822/problem/I)
def all_factors(n: int):
    fa = [1]
    for x, c in prime_elements(n):
        k = len(fa)
        for i in range(c * k):
            fa.append(fa[i] * x)
    fa.sort()
    return fa

initPrimes()

def init():
    w, l = map(int, input().split())
    return w, l

def solve(w: int, l: int) -> list[int]:
    ans = {1, 2}
    for x in all_factors(gcd(w - 1, l - 1)): 
        ans.add(x)
    for x in all_factors(gcd(w - 2, l)): 
        ans.add(x)
    for x in all_factors(gcd(w, l - 2)): 
        ans.add(x)
    return sorted(ans)

if __name__ == '__main__':
    for _ in range(int(input())):
        args = init()
        ans = solve(*args)
        print(len(ans), *ans)

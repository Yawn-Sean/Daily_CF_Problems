'''
https://codeforces.com/problemset/submission/396/294382248
396B
2024/12/2 Y1
1800
math
'''
# 奥数题 - 前面多个项拆出来后可以约掉
from math import gcd
import sys
input = lambda: sys.stdin.readline().strip()

MAXN = 31629
prime_factors = []
prime_set = []
def initPrimes():
    global prime_factors, prime_set, MAXN
    prime_factors = list(range(MAXN + 1))
    for i in range(2, int((MAXN) ** 0.5) + 1):
        if prime_factors[i] == i:
            prime_set.append(i)
            for j in range(i * i, MAXN + 1, i):
                if prime_factors[j] == j:
                    prime_factors[j] = i
    for i in range(int((MAXN) ** 0.5) + 1, MAXN + 1):
        if prime_factors[i] == i:
            prime_set.append(i)

def isPrime(n):
    global prime_factors, prime_set, MAXN
    if n <= MAXN:
        return prime_factors[n] == n
    else:
        for p in prime_set:
            if n % p == 0:
                return False
            elif p * p > n:
                return True
    return True

def init():
    n = int(input())
    return n

def solve(n: int) -> str:
    # x: max(p) that <= n, y: min(p) that > n
    x = n
    while not isPrime(x):
        x -= 1
    y = n + 1
    while not isPrime(y):
        y += 1
    a, b = x * y - (y << 1) + (n - x + 1 << 1), x * y << 1
    g = gcd(a, b)
    a, b = a // g, b // g
    return f"{a}/{b}"

if __name__ == '__main__':
    initPrimes()
    for _ in range(int(input())):
        n = init()
        ans = solve(n)
        print(ans)

import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
from math import isqrt

def build(N):
    is_prime = [False] * 2 + [True] * (N - 1)
    for i in range(2, isqrt(N) + 1):
        if is_prime[i]:
            for j in range(i * i, N + 1, i):
                is_prime[j] = False
    primes = [i for i, x in enumerate(is_prime) if x]
    return primes

def divs(x):
    ct = set()
    for i in range(2, isqrt(x) + 1):
        if x and x % i == 0:
            while x and x % i == 0:
                x //= i
            ct.add(i)
    if x > 1:
        ct.add(x)
    return ct

# WA: 8, time: 1.5hr, dt: 20250107
def solve():
    primes = build(int(2e6) + 25)
    used = set()
    b = a.copy()
    for i, x in enumerate(a):
        if used & (dx := divs(x)):
            x1 = x + 1
            while used & divs(x1): # 可以是合數
                x1 += 1
            b[i] = x1 
            used |= divs(x1)
            
            avail = [p for p in primes if p not in used]
            b[i+1:] = avail[:n-(i+1)]
            break
        used |= dx
    print(*b)
               
for _ in range(1):
    n = int(input())
    a = list(MII())
    solve()
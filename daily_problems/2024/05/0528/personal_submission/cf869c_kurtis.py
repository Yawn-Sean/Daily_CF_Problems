import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

def init():
    fact[0] = infact[0] = 1
    for i in range(1, 5001):
        fact[i] = fact[i - 1] * i % mod
        infact[i] = infact[i - 1] * pow(i, mod - 2, mod) % mod

def C(a, b):
    return fact[a] * infact[b] % mod * infact[a - b] % mod

def f(x, y):
    res = 0
    for i in range(min(x, y) + 1):
        res += C(x, i) * C(y, i) % mod * fact[i] % mod
        res %= mod
    return res

mod = 998244353
a, b, c = MII()
fact, infact = [0] * 5001, [0] * 5001
init()
print(f(a, b) * f(b, c) % mod * f(c, a) % mod)
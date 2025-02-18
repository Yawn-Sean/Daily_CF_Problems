import math
M = 10**9 + 7
R = 10**4
Fact = [1] * (R + 1)
for i in range(2, R + 1):
    Fact[i] = (i * Fact[i - 1]) % M
Facthyp = [1] * (R + 1)
Facthyp[R] = pow(Fact[R], M - 2, M)
for i in range(R - 1, -1, -1):
    Facthyp[i] = ((i + 1) * Facthyp[i + 1]) % M


def C(n, k):
    return math.comb(n, k) % M

n = int(input())
a = [int(e) - 1 for e in input().split()]
iu = [0] * n
xu = [0] * n
for i in range(n):
    if a[i] != -2:
        iu[i] = 1
        xu[a[i]] = 1
k = sum(not (iu[I] or xu[I]) for I in range(n))
n -= sum(iu)
y = 0
for i in range(k + 1):
    y += (-1 if i % 2 else 1) * C(k, i) * Fact[n - i]
    y %= M
print(y)

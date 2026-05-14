'''
https://codeforces.com/gym/106052/submission/374454946
Euler Function
'''

MAXN = 1000001
phi = []
phi_pre = []
def initPrimes():
    global phi, phi_pre
    phi = list(range(MAXN + 1))
    for i in range(2, MAXN + 1):
        if phi[i] == i:
            for j in range(i, MAXN + 1, i):
                phi[j] = phi[j] // i * (i - 1)
    phi_pre = phi # only 128MB limit, need to reuse memory
    phi_pre[1] = 0
    for i in range(2, MAXN + 1):
        if i & 1 == 0:
            phi_pre[i] = 0
        phi_pre[i] += phi_pre[i - 1]

def solve(n: int) -> int:
    return n + sum(phi_pre[n // i] << 1 for i in range(1, n + 1))


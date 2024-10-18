import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())

MOD = 10**9+7
MX = 2600
f = [1] * (MX + 1)
g = [1] * (MX + 1)
for i in range(2, MX+1):
    f[i] = f[i-1] * i % MOD
g[-1] = pow(f[-1], -1, MOD)
for i in range(MX, 1, -1):
    g[i-1] = g[i] * i % MOD

comb = lambda n, m: f[n] * g[m] * g[n-m] % MOD
get = lambda n, m: comb(n+m-1, m-1)

def solve():
    s = input()
    n = len(s)
    s = sum(ord(ch)-97 for ch in s)
    ans = -1
    for i in range(n):
        if s < 0: break
        ans += (-1 if i % 2 else 1) * comb(n, i) * get(s, n)
        s -= 26
    return ans % MOD

for _ in range(ii()):
    print(solve())

import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
from math import comb, isqrt
MOD = int(1e9 + 7)

def build(n):
    min_div = list(range(n + 1))
    for i in range(2, isqrt(n) + 1):
        if min_div[i] == i:
            for j in range(i * i, n + 1, i):
                if min_div[j] == j:
                    min_div[j] = i
    return min_div
    
def solve():
    min_div = build(r + 1)
    
    # Key: f[n] = min((n//i)*comb(i, 2) + f[i]), for i | n
    # comb(i, 2)是平方的，i越小越好(大於1)
    f = [1] * (r + 1)
    for i in range(2, r + 1):
        if min_div[i] == i:
            f[i] = comb(i, 2) % MOD
            continue
        k = min_div[i]
        groups = i // k
        comparisons_in_groups = comb(k, 2) % MOD
        f[i] = (groups * comparisons_in_groups + f[groups]) % MOD
    
    ans = 0
    for i in range(r, l - 1, -1):
        ans = (ans * t + f[i]) % MOD # Horner’s method
    print(ans)
               
for _ in range(1):
    t, l, r = MII()
    solve()
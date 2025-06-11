import sys, random
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
MOD = int(1e9 + 7)
from collections import Counter

n, k = MII()
fac = [1] * (n + 1)
for i in range(1, n):
    fac[i + 1] = fac[i] * (i + 1) % MOD

inv_fac = [0] * (n + 1)
inv_fac[-1] = pow(fac[-1], MOD - 2, MOD)
for i in range(n - 1, -1, -1):
    inv_fac[i] = inv_fac[i + 1] * (i + 1) % MOD

def comb(x, k):
    if x < k:
        return 0
    return fac[x] * inv_fac[k] * inv_fac[x - k] % MOD   

def solve():
    # Key: 全部取k次交集，那個數x會出現k次
    # 單個x會出現c(n,k)次，用差分計算累加次數
    d = Counter()
    rnd = random.getrandbits(20) # 避免dict碰撞
    for _ in range(n):
        l, r = MII()
        d[l + rnd] += 1
        d[r + 1 + rnd] -= 1
    
    ans = cur = 0
    ks = sorted(d)
    for i in range(len(ks) - 1):
        l, r = ks[i], ks[i + 1]
        cur += d[l]
        ans = (ans + comb(cur, k) * (r - l)) % MOD
    print(ans)
      
solve()
import sys
from itertools import accumulate
from functools import reduce
input = lambda: sys.stdin.readline().strip()
MOD = 998244353

def mod_mul(x, y):
    return x * y % MOD

n = int(input())
cnt = [0] * n
for _ in range(n - 1):
    u, v = map(lambda x: int(x) - 1, input().split())
    cnt[u] += 1
    cnt[v] += 1

f = [1] + list(accumulate(list(range(1, n + 1)), mod_mul))
res = reduce(mod_mul, [n] + [f[cnt[i]] for i in range(n)])
print(res)

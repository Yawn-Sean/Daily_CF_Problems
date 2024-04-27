import sys
import math
sys.stdin = open('in.txt', 'r')

input = lambda: sys.stdin.readline().strip()
write = lambda x: sys.stdout.write(str(x) + '\n')

mod = 998244353
n, m = map(int, input().split())
g = [list(map(int, input().split())) for _ in range(n)]

inv = 1
for i in range(1, n + 1):
    inv = inv * i % mod
inv = pow(inv, mod - 2, mod)

ret = 0

for i in range(m):
    cnt = [0] * (n + 2)
    for j in range(n):
        cnt[min(g[j][i], n + 1)] += 1
    s = 0
    cur = 1
    for j in range(n + 1, 1, -1):
        s += cnt[j]
        cur = cur * s % mod
        s -= 1
    ret = (ret + 1 - cur * inv) % mod

write(ret)

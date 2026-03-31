from array import array
from sys import exit

n = int(input())
if n == 1:
    exit(print("1"))
a = [tuple(map(int, input().split())) for _ in range(n)]

masks = [set() for _ in range(n)]
for i, (xi, yi) in enumerate(a):
    for j in range(i):
        xj, yj = a[j]
        res = (1 << i) | (1 << j)
        for k, (xk, yk) in enumerate(a):
            if (xj - xi) * (yk - yi) == (xk - xi) * (yj - yi):
                res |= 1 << k
        masks[i].add(res)
        masks[j].add(res)

M = 1 << n
dp = array('b', [0x7f] * M)
M -= 1
dp[0] = 0
for s in range(M):
    x = M ^ s
    i = (x & (-x)).bit_length() - 1
    x = dp[s] + 1
    for t in masks[i]:
        t |= s
        dp[t] = dp[t] if dp[t] < x else x

print(dp[-1])

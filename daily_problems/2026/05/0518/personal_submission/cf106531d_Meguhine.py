import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
p = list(map(int, input().split()))
S = sum(p)

if min(p) * n == S:  # same as `min(p) == max(p)`
    print(S - 1)  # K
    print(' '.join('1' * n))  # A
    print(' '.join(map(str, range(1, n + 1))))  # B
    print(' '.join('0' * n))  # C
    sys.exit(0)

A = [0] * n
B = [0] * n
C = [0] * n

for i in range(n):
    p[i] *= n

INF = 1 << 40  # (10**9 * 10**3) < (1 << 40)
for _ in range(n):
    p_mn = min(range(n), key=lambda x: p[x] if p[x] else INF)
    mn = p[p_mn]
    if mn >= S:
        p[p_mn] -= S
        A[_], B[_], C[_] = 1, p_mn + 1, 0
        continue
    p_mx = min(range(n), key=lambda x: p[x] if (x != p_mn and p[x] + mn >= S) else INF)
    mx = p[p_mx]
    assert mn + mx >= S
    p[p_mn] = 0
    p[p_mx] -= S - mn
    A[_], B[_], C[_] = p_mn + 1, p_mx + 1, mn

print(S - 1)  # K
print(' '.join(map(str, A)))
print(' '.join(map(str, B)))
print(' '.join(map(str, C)))

"""
我们取 K := S - 1, 这样就变成了:
sum(C_x) + sum(S - C_x) = N * P_i
对于每个 x
- A_x 能加上 [0, S - 1]
- B_x 能加上 [1, S]
考虑排序, 每次取出**当前**剩余最少和加起来刚好>=S的凑一对
可以用反证法证明一定可以
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

MOD = 10**9+7

def mat_mul(A, B):
    h, w = len(A), len(B[0])
    ans = [[0] * w for _ in range(h)]
    for i in range(h):
        for j in range(w):
            ans[i][j] = sum(A[i][k] * B[k][j] for k in range(len(A[0]))) % MOD
    return ans

def mat_qpow(A, k):
    sz = len(A)
    ans = [[0] * sz for _ in range(sz)]
    for i in range(sz):
        ans[i][i] = 1
    prod = A
    while k:
        if k & 1:
            ans = mat_mul(ans, prod)
        prod = mat_mul(prod, prod)
        k >>= 1
    return ans

def solve():
    n, l, m = lii()
    enter = lii()
    layer = lii()
    leave = lii()

    A = [[0] * m]
    for x in enter:
        A[0][x] += 1

    ways = [0] * m
    for x in layer:
        ways[x] += 1
    B = [[0] * m for _ in range(m)]
    for i in range(m):
        for j in range(m):
            B[i][j] = ways[(j-i)%m]

    C = [[0] for _ in range(m)]
    for x, y in zip(layer, leave):
        C[(-x-y)%m][0] += 1

    ans = mat_mul(mat_mul(A, mat_qpow(B, l-2)), C)
    return ans[0][0]

print(solve())
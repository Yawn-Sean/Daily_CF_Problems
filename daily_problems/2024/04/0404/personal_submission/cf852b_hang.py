# 矩阵快速幂
# https://oi-wiki.org/math/linear-algebra/matrix/#%E7%9F%A9%E9%98%B5%E5%8A%A0%E9%80%9F%E9%80%92%E6%8E%A8
def matrix_mul(A, B, mod=10 ** 9 + 7):
    assert len(A[0]) == len(B)
    h, mid = len(A), len(A[0])
    w = len(B[0])
    res = [[0] * w for _ in range(h)]
    for i in range(h):
        for k in range(mid):
            for j in range(w):
                res[i][j] += A[i][k] * B[k][j]
                res[i][j] %= mod
    return res


def matrix_pow(A, k, mod=10 ** 9 + 7):
    assert len(A) == len(A[0])
    n = len(A)
    b = A
    res = [[0] * n for _ in range(n)]
    for i in range(n):
        res[i][i] = 1
    while k:
        if k % 2:
            res = matrix_mul(res, b, mod)
        b = matrix_mul(b, b, mod)
        k //= 2
    return res
def main():
    N,L,M = map(int,input().split())
    input_list = list(map(int,input().split()))
    layer_list = list(map(int,input().split()))
    output_list = list(map(int,input().split()))
    z = [[0] * M]
    p = [0] * M
    for i in range(N):
        z[0][input_list[i] % M] += 1
        p[layer_list[i] % M] += 1
    g = [[0] * M for _ in range(M)]
    for i in range(M):
        for j in range(M):
            g[i][(i + j) % M] = p[j]
    dp = matrix_mul(z, matrix_pow(g, L - 2))[0]
    ans = 0
    for i in range(N):
        ans += dp[(- layer_list[i] - output_list[i]) % M]
    print(ans % (10 ** 9 + 7))





main()
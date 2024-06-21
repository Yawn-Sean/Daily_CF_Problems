a,b,n,x = RII()
mod = 10 ** 9 + 7
#快速幂
def matrix_multiply(a, b, MOD):
    m, n, p = len(a), len(a[0]), len(b[0])
    ans = [[0] * p for _ in range(m)]
    for i in range(m):
        for j in range(n):
            for k in range(p):
                ans[i][k] = (ans[i][k] + (a[i][j] * b[j][k]) % MOD) % MOD
    return ans


def matrix_pow_mod(a, b, MOD):
    n = len(a)
    ans = [[0] * n for _ in range(n)]
    for i in range(n):
        ans[i][i] = 1
    while b:
        if b & 1:
            ans = matrix_multiply(ans, a, MOD)
        a = matrix_multiply(a, a, MOD)
        b >>= 1
    return ans

grid = [[a,b],[0,1]]
opt = matrix_pow_mod(grid, n, mod)
fin = [[x],[1]]
print(matrix_multiply(opt,fin,mod)[0][0])

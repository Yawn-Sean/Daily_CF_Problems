import sys

# region fastio
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))
# endregion fastio

# MOD = 998_244_353
MOD = 10 ** 9 + 7
# DIR4 = ((-1, 0), (0, 1), (1, 0), (0, -1)) #URDL
# DIR8 = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))

# 矩阵乘法
def matrix_mul(A: list, B: list, MOD: int = MOD) -> list:
    n, m = len(A), len(A[0])
    p = len(B[0])
    ans = [[0] * p for _ in range(n)]
    for i in range(n):
        for j in range(m):
            for k in range(p):
                ans[i][k] += A[i][j] * B[j][k]
                ans[i][k] %= MOD
    return ans
# 矩阵快速幂
def matrix_pow(A: list, n: int) -> list:
    length = len(A)
    tmp = A
    ans = [[0] * length for _ in range(length)]
    for i in range(length):
        ans[i][i] = 1
    for i in range(30):
        if n % 2:
            ans = matrix_mul(ans, tmp)
        tmp = matrix_mul(tmp, tmp)
        n //= 2
    return ans

def solve() -> None:
    n, b, k, x = mint()
    nums = ints()
    cnt = [0] * 10
    for a in nums:
        cnt[a] += 1
    mat = [[0] * x for _ in range(x)]
    for i in range(x):
        for j in range(10):
            mat[i][(i * 10 + j) % x] += cnt[j]
    print(matrix_pow(mat, b)[0][k])

solve()

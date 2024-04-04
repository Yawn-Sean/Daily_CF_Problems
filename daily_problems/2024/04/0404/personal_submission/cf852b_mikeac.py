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
    n, l, m = mint()
    fst = ints()
    mid = ints()
    lst = ints()

    cnt = [0] * m
    for x in mid:
        cnt[x % m] += 1
    
    mat = [[0] * m for _ in range(m)]
    for i in range(m):
        for j in range(m):
            mat[i][(i + j) % m] = cnt[j]
    
    start = [[0] * m]
    for x in fst:
        start[0][x % m] += 1
    
    dp = matrix_mul(start, matrix_pow(mat, l - 2), MOD)[0]
    ans = 0
    for i in range(n):
        ans = (ans + dp[(-mid[i] - lst[i]) % m]) % MOD
    print(ans)



solve()

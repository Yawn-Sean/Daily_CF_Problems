import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 一定是2的倍数，用dp肯定与这个无关

n, k = MII()
f = [[0] * (2 * n + 1) for _ in range(4)] # 省略第一维
f[0][1] = f[1][2] = f[2][2] = f[3][1] = 1 # 初始化，都是1

mod = 998244353
inc = [[0, 1, 1, 1],
       [0, 0, 2, 0],
       [0, 2, 0, 0],
       [1, 1, 1, 0]]

for _ in range(n - 1):
    nf = [[0] * (2 * n + 1) for _ in range(4)]
    for i in range(4):
        for j in range(k + 1):
            if f[i][j]:
                for ni in range(4):
                    nf[ni][j + inc[i][ni]] += f[i][j]
                    nf[ni][j + inc[i][ni]] %= mod
    f = nf
print(sum(f[i][k] for i in range(4)) % mod)
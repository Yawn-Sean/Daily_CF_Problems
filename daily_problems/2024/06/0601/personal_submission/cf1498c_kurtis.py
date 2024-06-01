import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

mod = 10 ** 9 + 7
t = II()
ans = []
for _ in range(t):
    n, k = MII()
    f = [[0] * (k + 1) for _ in range(n + 1)] # f[i][j]表示前面还有i个板子，当前半衰期为k的所有方案
    # 然后从j开始枚举，因为第一维的大小不确定
    for j in range(1, k + 1):
        f[0][j] = 1
        for i in range(1, n + 1):
            f[i][j] = (f[i - 1][j] + f[n - i][j - 1]) % mod
    
    ans.append(f[n][k])
print(*ans, sep='\n')

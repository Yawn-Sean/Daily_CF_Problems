import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 要求出以每个位置为起点的最终结果，所以肯定不是模拟
# 0代表必输态；1代表必胜态，即它可以移动到某个0上
n = II()
perm = LMII()
pos = [0] * (n + 1) # 记录值的位置
for i in range(n):
    pos[perm[i]] = i

dp = [0] * n # 表示某个位置的状态值

# 从大到小求dp值，确保不会成环
for i in range(n, 0, -1):
    for j in range(pos[i] % i, n, i):
        if perm[j] > i and dp[j] == 0: # 是否能转移到一个必输态
            dp[pos[i]] = 1
            break

print(''.join('BA'[x] for x in dp))
import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 最大化物品个数
# 预处理每个答案的最小花费

ans = []
for _ in range(II()):
    n, p, k = MII()
    a = [0] + LMII()
    a.sort()
    # 还必须选k个
    f = [0] * (n + 1)
    for i in range(1, k):
        f[i] += f[i - 1] + a[i]
    for i in range(k, n + 1):
        f[i] += f[i - k] + a[i]
    for i in range(n, -1, -1):
        if p >= f[i]:
            ans.append(i)
            break

print(*ans, sep='\n')
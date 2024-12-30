import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 只考虑交换相邻两个人
n = II()
p = [LMII() for _ in range(n)]
p.sort(key=lambda x: x[1] - x[0])
print(sum(p[i][0] * i + p[i][1] * (n - 1 - i) for i in range(n)))
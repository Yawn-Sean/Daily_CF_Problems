import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 让出现次数最大的同时，最大次数的值最小
n, k = MII()
a = [-10 ** 10] + LMII()
a.sort()

# 前缀和+二分
ans, v = 0, 0
acc = [0] * (n + 1)
for i in range(1, n + 1):
    # 枚举a[i]为最终值
    acc[i] = acc[i - 1] + a[i]
    l, r = 1, i
    while l < r:
        m = l + r >> 1
        if k >= a[i] * (i - m + 1) - (acc[i] - acc[m - 1]):
            r = m
        else:
            l = m + 1
    if i - r + 1 > ans:
        ans = i - r + 1
        v = a[i]
print(ans, v)
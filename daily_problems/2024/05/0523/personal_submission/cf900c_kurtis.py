import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

n = II()
nums = LGMI()
cnt = [0] * n
d1, d2 = -1, -1 # 太妙了，其实就只跟最大值和次大值有关
for x in nums:
    if x > d1:
        cnt[x] -= 1
        d1, d2 = x, d1
    elif x > d2:
        cnt[d1] += 1
        d2 = x

print(cnt.index(max(cnt)) + 1) # 因为前面下标减了1
import sys
from math import inf

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/958/F2

给你一个 n 长数列 A 与一个 m 长数列 B。请你从 A 中找出连续的一段，使得删除最少的元素后，满足——区间中值为 i 的元素刚好有 B[i] 个。
请输出最少删除的元素数量。
'''
n, m = RII()
a, b = RILIST(), [0] + RILIST()
cnt = [0]*(m + 1)
s = t = 0 # 统计次数要求为0的，直接计入已满足要求的元素数。t表示满足要求需要的元素数量和
for x in b[1:]:
    if x == 0:
        s += 1
    t += x

l = 0
ans = inf
for r, x in enumerate(a):
    cnt[x] += 1
    if cnt[x] == b[x]:
        s += 1
    while l <= r and s == m:
        ans = mn(ans, r - l + 1 - t) # 有m个元素数量都大于等于要求数量了，减去恰好满足要求的数量，就是多余的需要删除的数量
        cnt[a[l]] -= 1
        if cnt[a[l]] < b[a[l]]:
            s -= 1
        l += 1
print(ans if ans < inf else -1)
# -*- coding : utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

n = I()
nums = LI()
N = max(nums) + 1
cnt = [0] * N

for num in nums:
    cnt[num] += 1

g = [[] for _ in range(N)]
for x in range(2, N):
    y = x // 2
    g[x].append(y)
    g[y].append(x)

depth = [-1] * N
fa = [-1] * N
dfs = []
stk = [1]
fa[1] = n
depth[1] = 1

while stk:
    x = stk.pop()
    dfs.append(x)
    for y in g[x]:
        if fa[y] == -1:
            fa[y] = x
            depth[y] = depth[x] + 1
            stk.append(y)
fa[1] = -1
# print(dfs)

size = [0] * N
for x in dfs[::-1]:
    size[x] += cnt[x]
    if fa[x] >= 0:
        size[fa[x]] += size[x]

st = max(x for x in range(1, N) if size[x] == n)
# print(st)

tot = sum(cnt[x] * (depth[x] - depth[st]) for x in range(1, N))
rets = [tot]
x = st * 2
while x < N:
    tmp = rets[-1] + (n - size[x]) - size[x]
    rets.append(tmp)
    x = x * 2

print(min(rets))


import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 又没看清题目，查询之间是相互影响的
n, m = MII()
s = list(I())
# 维护每个点左右两边1的个数即可
ans = 0
pre = 0 
l, r = [0] * n, [0] * n
for i, c in enumerate(s):
    l[i] = pre
    if c == '.':
        pre += 1
    elif pre:
        ans += pre - 1
        pre = 0
ans += max(0, pre - 1)
pre = 0
for i in range(n - 1, -1, -1):
    c = s[i]
    r[i] = pre
    if c == '.':
        pre += 1
    elif pre:
        pre = 0

outs = []
for _ in range(m):
    i, c = I().split()
    i = int(i) - 1
    if c == '.' and s[i] != '.':
        ans += l[i] + r[i] - (max(0, l[i] - 1) + max(0, r[i] - 1))
        if i > 0:
            r[i - 1] = r[i] + 1
        if i + 1 < n:
            l[i + 1] = l[i] + 1

    elif c != '.' and s[i] == '.':
        ans += max(0, l[i] - 1) + max(0, r[i] - 1) - (l[i] + r[i])
        if i > 0:
            r[i - 1] = 0
        if i + 1 < n:
            l[i + 1] = 0
    s[i] = c
    outs.append(ans)

print(*outs, sep='\n')
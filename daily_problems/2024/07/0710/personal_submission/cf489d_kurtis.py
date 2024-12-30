import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 太妙了，枚举a的后继b，然后枚举b的后继c，这样a到c的路径就记录了一条。最后再选两条作为一组答案即可
n, m = MII()
g = [[] for _ in range(n)]

for _ in range(m):
    a, b = GMI()
    g[a].append(b)

ans = 0
cnt = [0] * n
for i in range(n):
    for j in g[i]:
        for k in g[j]:
            cnt[k] += 1
    for j in range(n):
        if j != i:
            ans += cnt[j] * (cnt[j] - 1) // 2
        cnt[j] = 0
print(ans)
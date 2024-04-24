# 快读板子
import sys
RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())

n = RI()
N = 100005
g = [0]*N
h = [0]*N
tot = 0  # 右侧点数
a = RILIST()
for i,x in enumerate(a,1):
    if not g[x]:
        tot += 1
        g[x] = tot
        h[tot] = x
        g[i] = tot
    elif h[g[x]] == x:
        g[i] = g[x]
    else:
        print(-1)
        exit()
print(tot)
print(' '.join(str(x) for x in g[1:n + 1]))
print(' '.join(str(x) for x in h[1:tot + 1]))
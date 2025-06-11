import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 长度不同直接寄，否则每个不同的字符，选一个更小的代价
# 选代价，不只是可以变换一次
def get(c):
    return ord(c) - ord('a')

def floyd():
    for k in range(26):
        for i in range(26):
            for j in range(26):
                g[i][j] = min(g[i][j], g[i][k] + g[k][j])

s, t = I(), I()
n = II()
g = [[1000] * 26 for _ in range(26)]
for i in range(26):
    g[i][i] = 0

for _ in range(n):
    u, v, c = I().split()
    c = int(c)
    u, v = get(u), get(v)
    g[u][v] = min(g[u][v], c)

floyd()

if len(s) != len(t):
    exit(print(-1))

ans = []
c = 0
for i in range(len(s)):
    u, v = s[i], t[i]
    if u != v:
        a, b = get(u), get(v)
        mn, op = 201, None
        for i in range(26):
            if g[a][i] + g[b][i] < mn:
                mn, op = g[a][i] + g[b][i], i
        if mn == 201:
            exit(print(-1))
        ans.append(chr(op + ord('a')))
        c += mn
    else:
        ans.append(u)
print(c)
print(''.join(ans))
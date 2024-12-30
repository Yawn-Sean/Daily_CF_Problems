N = 7232
fa = list(range(N))
du = [0] * N
dis = [0] * N
s = [''] * N
cnt = 0
h = [[] for _ in range(N)]
num = 0
sum = 0

def getfa(x):
    if fa[x] == x:
        return x
    fa[x] = getfa(fa[fa[fa[fa[x]]]])
    return fa[x]

def merge(u, v):
    fu = getfa(u)
    fv = getfa(v)
    fa[fu] = fv

def add(u, v):
    global cnt
    du[v] += 1
    h[u].append(v)

def mx(x, y):
    return max(x, y)

n, m = map(int, input().split())
for i in range(1, n + m + 1):
    fa[i] = i

for i in range(1, n + 1):
    s[i] = '?' + input().strip()
    for j in range(1, m + 1):
        if s[i][j] == '=':
            merge(i, n + j)

for i in range(1, n + 1):
    for j in range(1, m + 1):
        if s[i][j] == '>':
            add(getfa(n + j), getfa(i))
        elif s[i][j] == '<':
            add(getfa(i), getfa(n + j))

q = deque()
for i in range(1, n + m + 1):
    if fa[i] == i:
        if du[i] == 0:
            dis[i] = 1
            q.append(i)
        sum += 1

while q:
    tmp = q.popleft()
    num += 1
    for v in h[tmp]:
        dis[v] = mx(dis[v], dis[tmp] + 1)
        du[v] -= 1
        if du[v] == 0:
            q.append(v)

if num != sum:
    print("No")
else:
    print("Yes")
    for i in range(1, n + 1):
        print(dis[getfa(i)], end=' ')
    print()
    for i in range(n + 1, n + m + 1):
        print(dis[getfa(i)], end=' ')

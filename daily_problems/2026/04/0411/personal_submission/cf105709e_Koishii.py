class UniFind:
    mx = 1
    def __init__(self, _n):
        self.n = _n
        self.p = [i for i in range(self.n + 1)]
        self.siz = [1] * (self.n + 1)

    def find(self, x):
        if self.p[x] != x: self.p[x] = self.find(self.p[x])
        return self.p[x]
    
    def merge(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y: return
        self.siz[y] += self.siz[x]
        self.p[x] = y
        self.mx = max(self.mx, self.siz[y])



outs = []
n, k, q = map(int, input().split())

se = [[[] for _ in range(10)] for i in range(k)]

for i in range(n):
    s = input()
    for j in range(k):
        d = ord(s[j]) - ord('a')
        se[j][d].append(i)


dsu = UniFind(n)

vis = [False] * k
for query in range(q):
    data = list(map(int, input().split()))
    if data[0] == 1: # k*10*n
        x = data[1] - 1
        if vis[x]: continue
        else: vis[x] = True
        for j in range(10):
            for i in range(1, len(se[x][j])):
                dsu.merge(se[x][j][i], se[x][j][i - 1])
            
    elif data[0] == 2:
        x = data[1] - 1
        outs.append(dsu.siz[dsu.find(x)])

    else:
        outs.append(dsu.mx)

print('\n'.join(map(str, outs)))

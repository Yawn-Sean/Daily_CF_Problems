import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
    
    def find(self, u):
        while u != self.p[u]:
            self.p[u] = self.p[self.p[u]]
            u = self.p[u]
        return u

    def join(self, u, v):
        u, v = self.find(u), self.find(v)
        if u != v:
            self.p[v] = u
            return True
        return False

def solve():  
    edges = []
    for _ in range(m):
        u, v, s = MII()
        edges.append((s, u - 1, v - 1))
    edges.sort()
    
    uf = UnionFind(n)
    taken, extra = [], []
    for s, u, v in edges:
        if uf.join(u, v):
            taken.append(s)
        else:
            extra.append(s)
    
    if taken[-1] < k:
        cost = k - taken[-1]
    else:
        cost = 0
        for x in reversed(taken):
            if x <= k:
                break
            cost += x - k
            
    if taken[-1] < k: # 這樣才有機會替換(minST)
        for x in extra:
            cost = min(cost, abs(k - x))
    print(cost)
                    
for _ in range(int(input())):
    n, m, k = MII()
    solve()
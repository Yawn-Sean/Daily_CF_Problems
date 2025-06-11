# Submission link: https://codeforces.com/contest/305/submission/287591312

mod = 10 ** 9 + 7
class UnionFind:
    def __init__(self, n):
        self.parent_or_size = [-1] * n
        self.depth = [0] * n
 
    def find(self, a):
        acopy = a
        v = 0
        
        while self.parent_or_size[a] >= 0:
            v += self.depth[a]
            if v >= mod: v -= mod
            a = self.parent_or_size[a]
        
        while acopy != a:
            self.depth[acopy], v = v, v - self.depth[acopy]
            if v < 0: v += mod
            self.parent_or_size[acopy], acopy = a, self.parent_or_size[acopy]
        return a
 
    def merge(self, a, b, w):
        pa, pb = self.find(a), self.find(b)
        va, vb = self.getDepth(a), self.getDepth(b)
        
        w += va
        if w >= mod: w -= mod
        w -= vb
        if w < 0: w += mod
        
        self.parent_or_size[pa] += self.parent_or_size[pb]
        self.parent_or_size[pb] = pa
        self.depth[pb] = w
 
    def getDepth(self, a):
        self.find(a)
        return self.depth[a]

def main():
    n = II()
    dsu = UnionFind(n)
    ans = 0

    for i in range(n):
        tmp = LII()
        for j in range(1, len(tmp), 2):
            idx = tmp[j] - 1
            val = tmp[j + 1]
            if val < 0: val += mod
            
            val += dsu.getDepth(idx)
            if val >= mod: val -= mod
            
            ans += val
            if ans >= mod: ans -= mod
            
            u = dsu.find(idx)
            dsu.merge(i, u, val)

    print(ans)
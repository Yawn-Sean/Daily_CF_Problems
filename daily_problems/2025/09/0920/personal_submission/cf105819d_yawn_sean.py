# Submission link: https://codeforces.com/gym/105819/submission/339397092
def main():
    n, m = MII()
    nums = LII()
    
    us = []
    vs = []
    
    for _ in range(m):
        u, v = GMI()
        us.append(u)
        vs.append(v)
    
    uf = UnionFind(n)
    
    ans = [[0] * n for _ in range(n)]
    
    for i in range(30):
        uf.init()
        
        for j in range(m):
            u, v = us[j], vs[j]
            if nums[u] >> i & 1 and nums[v] >> i & 1:
                uf.merge(u, v)
        
        for x in range(n):
            for y in range(n):
                if uf.find(x) == uf.find(y):
                    ans[x][y] = 1
    
    print('\n'.join(''.join(map(str, x)) for x in ans))
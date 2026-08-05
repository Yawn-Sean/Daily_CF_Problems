# Submission link: https://codeforces.com/gym/106159/submission/385712027
def main():
    n = II()
    nums = LII()
    
    p = LGMI()
    path = [[] for _ in range(n)]
    
    for i in range(n):
        path[p[i]].append(i)
        path[i].append(p[i])
    
    ans = 0
    cur = 0
    
    uf = UnionFind(n)
    vis = [0] * n
    
    for i in sorted(range(n), key=lambda x: -nums[x]):
        vis[i] = 1
        cur += 1
        
        for j in path[i]:
            if vis[j]:
                if uf.find(i) != uf.find(j):
                    cur -= (uf.getSize(i) + 1) // 2
                    cur -= (uf.getSize(j) + 1) // 2
                    uf.merge(i, j)
                    cur += (uf.getSize(i) + 1) // 2
                else:
                    cur -= uf.getSize(i) % 2
        
        ans = fmax(ans, cur * nums[i])
    
    print(ans)
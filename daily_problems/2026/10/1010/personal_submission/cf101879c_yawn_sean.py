# Submission link: https://codeforces.com/gym/101879/submission/393784739
def main():
    n, m, k = MII()
    
    degs = [0] * n
    
    for _ in range(m):
        u, v = GMI()
        degs[u] ^= 1
        degs[v] ^= 1
    
    uf = UnionFind(n)
    path = [[] for _ in range(n)]
    
    for _ in range(k):
        u, v = GMI()
        if uf.merge(u, v):
            path[u].append(v)
            path[v].append(u)
    
    parent = [-1] * n
    
    que = [i for i in range(n) if uf.find(i) == i]
            
    for u in que:
        for v in path[u]:
            if parent[u] != v:
                parent[v] = u
                que.append(v)
    
    for u in reversed(que):
        if parent[u] != -1:
            degs[parent[u]] ^= degs[u]
    
    for i in range(n):
        if parent[i] == -1 and degs[i]:
            exit(print('NO'))
    
    print('YES')
    k = sum(degs)
    print(k)
    if k: print('\n'.join(f'{i + 1} {parent[i] + 1}' for i in range(n) if degs[i]))
# Submission link: https://codeforces.com/problemset/submission/990/322112774
def main():
    n = II()
    nums = LII()

    m = II()

    us = []
    vs = []

    path = [[] for _ in range(n)]
    dsu = UnionFind(n)

    for i in range(m):
        u, v = GMI()
        us.append(u)
        vs.append(v)
        
        if dsu.merge(u, v):
            path[u].append(i)
            path[v].append(i)

    parent = [-2] * n
    ans = [0] * m

    for i in range(n):
        if parent[i] == -2:
            parent[i] = -1
            
            que = [i]
            for u in que:
                for eid in path[u]:
                    v = us[eid] + vs[eid] - u
                    if parent[u] != v:
                        parent[v] = u
                        que.append(v)
            
            for j in range(len(que) - 1, 0, -1):
                u = que[j]
                p = parent[u]
                nums[p] += nums[u]
                
                for eid in path[u]:
                    v = us[eid] + vs[eid] - u
                    if v == p:
                        if us[eid] == u: ans[eid] = -nums[u]
                        else: ans[eid] = nums[u]

            if nums[i]:
                exit(print('Impossible'))

    print('Possible')
    print(*ans, sep='\n')
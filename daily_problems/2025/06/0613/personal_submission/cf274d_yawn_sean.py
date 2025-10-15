# Submission link: https://codeforces.com/contest/274/submission/324170809
def main():
    n, m = MII()
    grid = [LII() for _ in range(n)]

    path = [[] for _ in range(m + n * m)]
    indeg = [0] * (m + n * m)
    pt = m

    for i in range(n):
        idxs = [j for j in range(m) if grid[i][j] != -1]
        idxs.sort(key=lambda x: grid[i][x])
        
        l, r = 0, 0
        last_node = -1
        
        for j in range(1, len(idxs)):
            if grid[i][idxs[j]] == grid[i][idxs[j - 1]]:
                r = j
            else:
                if last_node != -1:
                    for idx in range(l, r + 1):
                        path[last_node].append(idxs[idx])
                        indeg[idxs[idx]] += 1
                
                for idx in range(l, r + 1):
                    path[idxs[idx]].append(pt)
                    indeg[pt] += 1

                last_node = pt
                pt += 1
                l = r = j
        
        if last_node!= -1:
            for idx in range(l, r + 1):
                path[last_node].append(idxs[idx])
                indeg[idxs[idx]] += 1

    stk = [i for i in range(m + n * m) if indeg[i] == 0]
    ans = []

    while stk:
        u = stk.pop()
        if u < m:
            ans.append(u)
        for v in path[u]:
            indeg[v] -= 1
            if indeg[v] == 0:
                stk.append(v)

    if len(ans) == m: print(' '.join(str(x + 1) for x in ans))
    else: print(-1)
'''
https://codeforces.com/problemset/submission/1320/307916492
'''
# 维护每个节点最短路径的长度，以及最短路径的数量
def solve(n: int, m: int, edges: list[list[int]], k: int, pa: list[int]) -> list[int]:
    # reverse graph
    g = [[] for _ in range(n + 1)]
    for u, v in edges:
        g[v].append(u)

    # bfs get all shortest paths to the destination
    vis = [[-1, -1] for _ in range(n + 1)]
    vis[pa[-1]][:] = 0, 1
    bfs = deque()
    bfs.append(pa[-1])
    while bfs:
        i = bfs.popleft()
        s, c = vis[i]
        for j in g[i]:
            if vis[j][0] < 0:
                vis[j][:] = s + 1, c
                bfs.append(j)
            elif vis[j][0] == s + 1:
                vis[j][1] += c

    # calc min and max rebuilds
    minr, maxr = 0, 0
    for i, j in pairwise(pa):
        si, ci = vis[i]
        sj, cj = vis[j]
        if si - 1 != sj:
            minr += 1
            maxr += 1
        elif ci != cj:
            maxr += 1
    return [minr, maxr]

# Submission link: https://codeforces.com/contest/276/submission/298609337
def main():
    n, q = MII()
    path = [[] for _ in range(n)]

    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)

    vis = [-1] * n
    vis[0] = 0

    depth = [0] * n
    chain_len = [0] * n

    fens = [None] * n

    for i in path[0]:
        vis[i] = i
        depth[i] = 1
        
        u = i
        while len(path[u]) != 1:
            v = path[u][0] if vis[path[u][0]] == -1 else path[u][1]
            depth[v] = depth[u] + 1
            vis[v] = i
            u = v
        
        fens[i] = FenwickTree(depth[u])
        chain_len[i] = depth[u]

    ans0 = 0
    outs = []

    total = FenwickTree(n)

    for _ in range(q):
        query = LII()
        if query[0]:
            v = query[1] - 1
            
            if v == 0: outs.append(ans0)
            else:
                chain_id = vis[v]
                outs.append(ans0 + total.rsum(0, depth[v] - 1) + fens[chain_id].rsum(0, depth[v] - 1))
        else:
            v = query[1] - 1
            x = query[2]
            d = query[3]
            
            chain_id = vis[v]
            if d < depth[v]:
                fens[chain_id].add(depth[v] - 1 - d, x)
                if depth[v] + d < chain_len[chain_id]:
                    fens[chain_id].add(depth[v] + d, -x)
            else:
                ans0 += x
                total.add(d - depth[v], -x)
                if v > 0:
                    fens[chain_id].add(d - depth[v], x)
                    if depth[v] + d < chain_len[chain_id]:
                        fens[chain_id].add(depth[v] + d, -x)

    print('\n'.join(map(str, outs)))
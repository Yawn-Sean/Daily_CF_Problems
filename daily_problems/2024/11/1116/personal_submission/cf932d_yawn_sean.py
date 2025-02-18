# Submission link: https://codeforces.com/contest/932/submission/291725411
def main():
    q = II()

    cur = 1
    last = 0

    parent = [[0] * (q + 5) for _ in range(20)]
    parent_weight = [[0] * (q + 5) for _ in range(20)]
    chain_parent = [[0] * (q + 5) for _ in range(20)]
    chain_parent_weight = [[0] * (q + 5) for _ in range(20)]

    inf = 2 * 10 ** 15

    for i in range(20):
        parent_weight[i][0] = inf
        chain_parent_weight[i][0] = inf
        if i > 0:
            chain_parent_weight[i][1] = inf

    outs = []
    for _ in range(q):
        t, p, q = MII()
        p ^= last
        q ^= last
        
        if t == 1:
            cur += 1
            
            u = cur
            parent[0][u] = p
            parent_weight[0][u] = q
            chain_parent[0][u] = p
            chain_parent_weight[0][u] = q
            
            for i in range(1, 20):
                p = parent[i - 1][u]
                parent[i][u] = parent[i - 1][p]
                parent_weight[i][u] = fmax(parent_weight[i - 1][u], parent_weight[i - 1][p])
            
            for i in range(19, -1, -1):
                if parent_weight[i][chain_parent[0][u]] < q:
                    chain_parent[0][u] = parent[i][chain_parent[0][u]]
            
            for i in range(1, 20):
                p = chain_parent[i - 1][u]
                chain_parent[i][u] = chain_parent[i - 1][p]
                chain_parent_weight[i][u] = chain_parent_weight[i - 1][u] + chain_parent_weight[i - 1][p]
                if chain_parent_weight[i][u] > inf:
                    for j in range(i, 20):
                        chain_parent_weight[j][u] = inf
                    break
            
        else:
            last = 0
            for i in range(19, -1, -1):
                if q >= chain_parent_weight[i][p]:
                    q -= chain_parent_weight[i][p]
                    p = chain_parent[i][p]
                    last += 1 << i

            outs.append(last)

    print('\n'.join(map(str, outs)))
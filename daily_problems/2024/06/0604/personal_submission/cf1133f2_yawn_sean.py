# Submission link: https://codeforces.com/contest/1133/submission/264069216
def main():
    n, m, d = MII()

    us = []
    vs = []
    to1 = []

    for i in range(m):
        u, v = GMI()
        us.append(u)
        vs.append(v)
        if u == 0 or v == 0:
            to1.append(i)

    if len(to1) < d:
        print('NO')
    else:
        union = UnionFind(n)
        for i in range(m):
            if us[i] and vs[i]:
                union.merge(us[i], vs[i])
        
        components = [0] * n
        for i in range(1, n):
            components[union.find(i)] = 1
        
        if sum(components) > d:
            print('NO')
        else:
            print('YES')
            chosen_edges = []
            used = [0] * len(to1)
            union1 = UnionFind(n)
            
            for idx, edge_id in enumerate(to1):
                u = us[edge_id] if us[edge_id] else vs[edge_id]
                if components[union.find(u)]:
                    components[union.find(u)] = 0
                    union1.merge(u, 0)
                    chosen_edges.append(f'{1} {u + 1}')
                    used[idx] = 1
                    d -= 1
            
            for idx, edge_id in enumerate(to1):
                if d and not used[idx]:
                    u = us[edge_id] if us[edge_id] else vs[edge_id]
                    union1.merge(u, 0)
                    chosen_edges.append(f'{1} {u + 1}')
                    d -= 1
            
            for i in range(m):
                if us[i] and vs[i] and union1.merge(us[i], vs[i]):
                    chosen_edges.append(f'{us[i] + 1} {vs[i] + 1}')
            
            print('\n'.join(chosen_edges))
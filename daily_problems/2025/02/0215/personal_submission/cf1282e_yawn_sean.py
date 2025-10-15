# Submission link: https://codeforces.com/contest/1282/submission/306152079
def main():
    t = II()
    outs = []

    for _ in range(t):
        n = II()
        edge_cnt = Counter()
        edge_from = defaultdict(list)
        
        triangles = []
        
        for t_id in range(n - 2):
            edge = LII()
            edge.sort()
            triangles.append(edge)
            
            for i in range(3):
                for j in range(i):
                    edge_cnt[(edge[j], edge[i])] += 1
                    edge_from[(edge[j], edge[i])].append(t_id)
        
        path = [[] for _ in range(n + 1)]
        for e in edge_cnt:
            if edge_cnt[e] == 1:
                u, v = e
                path[u].append(v)
                path[v].append(u)

        vis = [0] * (n + 1)
        nodes = [1]
        vis[1] = 1
        
        for _ in range(n - 1):
            for v in path[nodes[-1]]:
                if not vis[v]:
                    vis[v] = 1
                    nodes.append(v)
                    break
        
        
        outs.append(' '.join(map(str, nodes)))
        
        ans = []
        stk = []
        
        cnt = [3] * (n - 2)
        for i in range(n):
            u, v = nodes[i], nodes[i - 1]
            if u > v: u, v = v, u
            
            for t_id in edge_from[(u, v)]:
                cnt[t_id] -= 1
                
                if cnt[t_id] == 1:
                    stk.append(t_id)
        
        while stk:
            u = stk.pop()
            ans.append(u)
            
            for i in range(3):
                for j in range(i):
                    for v in edge_from[(triangles[u][j], triangles[u][i])]:
                        if cnt[v] > 0:
                            cnt[v] -= 1
                            if cnt[v] == 1:
                                stk.append(v)
        
        outs.append(' '.join(str(x + 1) for x in ans))

    print('\n'.join(outs))
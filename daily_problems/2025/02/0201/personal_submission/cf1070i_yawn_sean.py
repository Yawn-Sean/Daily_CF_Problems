# Submission link: https://codeforces.com/contest/1070/submission/303850133
def main():
    t = II()
    outs = []

    for _ in range(t):
        n, m, k = MII()
        path = [[] for _ in range(n)]
        
        mf = MFGraph(n + m + 2)
        src = n + m
        dst = n + m + 1
        
        for i in range(m):
            u, v = GMI()
            path[u].append(i)
            path[v].append(i)
            mf.add_edge(n + i, dst, 1)

        total_f = 0    
        for i in range(n):
            f = 2 * fmax(0, len(path[i]) - k)
            total_f += f
            mf.add_edge(src, i, f)
            for j in path[i]:
                mf.add_edge(i, n + j, 1)
        
        if mf.flow(src, dst) < total_f: outs.append(' '.join('0' for _ in range(m)))
        else:
            to_pair = [-1] * n
            ans = list(range(m))
            
            for edge in mf.edges():
                if edge.flow and edge.src < n:
                    u = edge.dst - n
                    if to_pair[edge.src] != -1:
                        ans[u] = to_pair[edge.src]
                        to_pair[edge.src] = -1
                    else:
                        to_pair[edge.src] = edge.dst - n
            
            outs.append(' '.join(str(x + 1) for x in ans))

    print('\n'.join(outs))
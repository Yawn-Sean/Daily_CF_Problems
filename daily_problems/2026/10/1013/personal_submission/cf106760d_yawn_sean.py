# Submission link: https://codeforces.com/gym/106760/submission/394245909
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, m = MII()
        path = [[] for _ in range(n)]
        
        for _ in range(m):
            u, v = GMI()
            path[u].append(v)
            path[v].append(u)
        
        vis = [[0] * n for _ in range(n)]
        
        for i in range(n):
            for j in path[i]:
                vis[i][j] = 1
            for j1 in path[i]:
                for j2 in path[i]:
                    vis[j1][j2] = 1
        
        out = []
        for i in range(n):
            for j in range(i + 1, n):
                if vis[i][j]:
                    out.append(f'{i + 1} {j + 1}')
        
        outs.append(f'{len(out)}')
        outs.extend(out)
    
    print('\n'.join(outs))
# Submission link: https://codeforces.com/gym/105822/submission/341615762
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, m, k = MII()
        visits = LGMI()
        
        path = [[] for _ in range(n)]
        
        for _ in range(m):
            u, v = GMI()
            path[u].append(v)
            path[v].append(u)
        
        cur = 0
        for x in visits:
            if x != cur:
                path[x].append(cur)
                path[cur].append(x)
                cur = x
        
        dis = [-1] * n
        dis[0] = 0
        
        que = [0]
        
        for u in que:
            for v in path[u]:
                if dis[v] == -1:
                    dis[v] = dis[u] + 1
                    que.append(v)
        
        flg = True
        for i in range(1, k):
            if dis[visits[i]] <= dis[visits[i - 1]]:
                flg = False
        
        if flg:
            outs.append(str(k if visits[0] else k - 1))
            cur = 0
            for x in visits:
                if x != cur:
                    outs.append(f'{cur + 1} {x + 1}')
                    cur = x
        else:
            outs.append('-1')
    
    print('\n'.join(outs))
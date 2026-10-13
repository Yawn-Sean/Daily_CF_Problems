# Submission link: https://codeforces.com/gym/103414/submission/394354171
def main():
    n = II()
    
    res = [0] * (n + 1)
    vis = [0] * (n + 1)
    
    next_query = (-1, -1)
    
    def query(x, y):
        global next_query
        next_query = (-1, -1)
        
        print('?', x, y, flush=True)
        s, vx, vy = MII()
        
        if vis[vy] == 0:
            if vx == vy:
                next_query = (1, vy)
            if vx == 1:
                next_query = (vy, vy)
        
        return s
    
    res[1] = query(1, 1)
    vis[1] = 1
    
    pt = 1
    
    for _ in range(n - 1):
        if next_query != (-1, -1):
            v = next_query[1]
            if next_query[0] == 1:
                vis[v] = 1
            else:
                vis[v] = 2
            res[v] = query(*next_query)
        else:
            while vis[pt]:
                pt += 1
            
            vis[pt] = 2
            res[pt] = query(pt, pt)
    
    ans = [0] * (n + 1)
    ans[1] = res[1]
    
    cur = res[1]
    
    for i in range(2, n + 1):
        if vis[i] == 2: ans[i] = res[i]
        else: ans[i] = res[i] - cur
        cur += ans[i]
    
    print('!')
    print(' '.join(map(str, ans[1:])))
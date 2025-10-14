# Submission link: https://codeforces.com/gym/102419/submission/343687213
def main():
    n, m = MII()
    nums = LII()
    vis = [0] * (1 << 20)
    
    path = [[] for _ in range(n)]
    
    for _ in range(m):
        u, v = GMI()
        if nums[u] == nums[v]:
            path[u].append(v)
            path[v].append(u)
        else:
            vis[nums[u] ^ nums[v]] = 1
    
    col = [-1] * n
    
    for i in range(n):
        if col[i] == -1:
            col[i] = 0
            
            stk = [i]
            while stk:
                u = stk.pop()
                
                for v in path[u]:
                    if col[v] == -1:
                        col[v] = col[u] ^ 1
                        stk.append(v)
                    elif col[u] == col[v]:
                        exit(print(-1))
    
    chosen = 1
    while vis[chosen]:
        chosen += 1
    
    print(sum(col), chosen)
    print(*(i + 1 for i in range(n) if col[i]))
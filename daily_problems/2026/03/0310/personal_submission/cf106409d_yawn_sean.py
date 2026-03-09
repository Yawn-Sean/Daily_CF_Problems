# Submission link: https://codeforces.com/gym/106409/submission/365988765
def main(): 
    n, m = MII()
    path = [[] for _ in range(n + 1)]
    
    for _ in range(m):
        u, v = MII()
        path[u].append(v)
        path[v].append(u)
    
    for u in range(n + 1):
        for v in path[u]:
            for x in path[u][:4]:
                for y in path[v][:4]:
                    if x != v and y != u and x != y:
                        print(x, u, v, y, sep='\n')
                        exit()
    
    print(-1)
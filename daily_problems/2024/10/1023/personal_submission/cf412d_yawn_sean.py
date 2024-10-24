# Submission link: https://codeforces.com/contest/412/submission/287443094
def main():
    n, m = MII()

    path = [[] for _ in range(n)]

    for _ in range(m):
        u, v = GMI()
        path[u].append(v)

    order = []
    vis = [0] * n
    tmp = [0] * n

    stk = []

    for i in range(n):
        
        if tmp[i] == 0:
            stk.append(i)
            tmp[i] = 1
            
            while stk:
                u = stk.pop()
                while vis[u] < len(path[u]):
                    
                    if tmp[path[u][vis[u]]] == 0:
                        stk.append(u)
                        stk.append(path[u][vis[u]])
                        tmp[path[u][vis[u]]] = 1
                        break
                    
                    vis[u] += 1
                else:
                    order.append(u)

    print(' '.join(str(x + 1) for x in order))
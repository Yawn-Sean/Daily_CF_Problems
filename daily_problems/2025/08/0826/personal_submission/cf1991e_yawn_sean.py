# Submission link: https://codeforces.com/contest/1991/submission/335502430
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
        
        col = [-1] * n
        v0 = []
        v1 = []
        flg = True
        
        for i in range(n):
            if col[i] == -1:
                col[i] = 0
                stk = [i]
                
                while stk:
                    u = stk.pop()
                    if col[u] == 0: v0.append(u)
                    else: v1.append(u)
                    
                    for v in path[u]:
                        if col[v] != -1:
                            if col[u] == col[v]:
                                flg = False
                        else:
                            col[v] = col[u] ^ 1
                            stk.append(v)
        
        if flg:
            print('Bob', flush=True)
            for _ in range(n):
                c1, c2 = MII()
                if (c1 == 1 or c2 == 1) and v0:
                    x = v0.pop()
                    print(x + 1, 1, flush=True)
                elif (c1 == 2 or c2 == 2) and v1:
                    x = v1.pop()
                    print(x + 1, 2, flush=True)
                elif v0:
                    x = v0.pop()
                    print(x + 1, 3, flush=True)
                else:
                    x = v1.pop()
                    print(x + 1, 3, flush=True)
        else:
            print('Alice', flush=True)
            for _ in range(n):
                print('1 2', flush=True)
                I()
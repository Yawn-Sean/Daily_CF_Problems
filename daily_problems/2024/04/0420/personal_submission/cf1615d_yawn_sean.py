# Submission link: https://codeforces.com/contest/1615/submission/257368465
def main():
    n, m = MII()
    us = []
    vs = []
    
    path = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v, w = GMI()
        w += 1
        if w != -1:
            path[u].append((v, w))
            path[v].append((u, w))
        us.append(u)
        vs.append(v)
    
    groups = [-1] * n
    ans = [-1] * n
    
    for i in range(n):
        if ans[i] == -1:
            stack = [i]
            ans[i] = 0
            
            while stack:
                u = stack.pop()
                groups[u] = i
                for v, w in path[u]:
                    if ans[v] == -1:
                        ans[v] = ans[u] ^ w
                        stack.append(v)
    
    path = [[] for _ in range(n)]
    for _ in range(m):
        u, v, c = GMI()
        c += 1
        if bin(ans[u] ^ ans[groups[u]]).count('1') % 2: c ^= 1
        if bin(ans[v] ^ ans[groups[v]]).count('1') % 2: c ^= 1
        u = groups[u]
        v = groups[v]
        if c:
            path[u].append(~v)
            path[v].append(~u)
        else:
            path[u].append(v)
            path[v].append(u)
    
    col = [-1] * n
    f = True
    for i in range(n):
        if col[i] == -1:
            col[i] = 0
            stack = [i]
            while stack:
                u = stack.pop()
                for v in path[u]:
                    if v < 0:
                        v = ~v
                        if col[v] == -1:
                            col[v] = col[u] ^ 1
                            stack.append(v)
                        elif col[u] == col[v]:
                            f = False
                    else:
                        if col[v] == -1:
                            col[v] = col[u]
                            stack.append(v)
                        elif col[u] != col[v]:
                            f = False

    print('YES' if f else 'NO')
    if f:
        for i in range(n):
            ans[i] ^= col[groups[i]]
        
        for i in range(n - 1):
            print(f'{us[i] + 1} {vs[i] + 1} {ans[us[i]] ^ ans[vs[i]]}')

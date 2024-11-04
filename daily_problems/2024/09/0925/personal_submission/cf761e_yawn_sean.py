# Submission link: https://codeforces.com/contest/761/submission/282847376
def main():
    n = II()
    path = [[] for _ in range(n)]

    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)

    for i in range(n):
        if len(path[i]) > 4:
            exit(print('NO'))

    pos = [None] * n
    pos[0] = (0, 0)

    stk = [(0, -1, 1 << 29)]
    dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]

    while stk:
        u, nd, msk = stk.pop()
        msk //= 2
        
        cur_d = 0
        
        for v in path[u]:
            if pos[v] is None:
        
                if cur_d == nd:
                    cur_d += 1
                
                dx, dy = dirs[cur_d]
                x = pos[u][0] + dx * msk
                y = pos[u][1] + dy * msk
                
                pos[v] = (x, y)
                stk.append((v, cur_d ^ 2, msk))
                
                cur_d += 1

    print('YES')
    for pt in pos:
        print(*pt)
# Submission link: https://codeforces.com/contest/717/submission/303311173
def main():
    n = II()
    cols = [II() for _ in range(n)]
    path = [[] for _ in range(n)]

    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)

    ops = [0]
    parent = [-1] * n

    def operate(u):
        cols[u] = -cols[u]
        ops.append(u)

    stk = [0]
    while stk:
        u = stk.pop()
        if u >= 0:
            if u > 0: operate(u)
            stk.append(~u)
            
            for v in path[u]:
                if parent[u] != v:
                    parent[v] = u
                    stk.append(v)
        else:
            u = ~u
            if u > 0:
                operate(parent[u])
            if cols[u] != 1:
                if u > 0:
                    operate(u)
                    operate(parent[u])
                else:
                    v = path[u][0]
                    operate(v)
                    operate(u)
                    operate(v)

    print(' '.join(str(x + 1) for x in ops))
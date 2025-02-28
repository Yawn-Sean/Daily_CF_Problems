# Submission link: https://codeforces.com/contest/1141/submission/306599793
def main():
    n, k = MII()
    us = []
    vs = []

    path = [[] for _ in range(n)]

    for i in range(n - 1):
        u, v = GMI()
        us.append(u)
        vs.append(v)
        path[u].append(i)
        path[v].append(i)

    degs = [len(x) for x in path]
    degs.sort()

    ans = degs[n - 1 - k]

    col = [-1] * (n - 1)

    stk = [0]
    while stk:
        u = stk.pop()
        
        vis = -1
        cur = 1
        
        for eid in path[u]:
            if col[eid] != -1:
                vis = col[eid]
        
        for eid in path[u]:
            if col[eid] == -1:
                if len(path[u]) > ans:
                    col[eid] = 1
                else:
                    if cur == vis: cur += 1
                    col[eid] = cur
                    cur += 1
                stk.append(us[eid] + vs[eid] - u)

    print(ans)
    print(' '.join(map(str, col)))
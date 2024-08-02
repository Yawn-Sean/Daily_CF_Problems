# Submission link: https://codeforces.com/contest/269/submission/273946402
def main():
    n, m = MII()

    us = []
    vs = []
    ws = []

    path = [[] for _ in range(n)]
    tot_flow = [0] * n

    for i in range(m):
        u, v, w = GMI()
        w += 1
        us.append(u)
        vs.append(v)
        ws.append(w)
        path[u].append(i)
        path[v].append(i)
        tot_flow[u] += w
        tot_flow[v] += w

    for i in range(n):
        tot_flow[i] //= 2

    notes = [-1] * m
    stk = [0]

    while stk:
        u = stk.pop()
        for i in path[u]:
            v = us[i] + vs[i] - u
            
            if notes[i] == -1:
                notes[i] = 0 if us[i] == u else 1
                tot_flow[v] -= ws[i]
                if tot_flow[v] == 0 and v != n - 1:
                    stk.append(v)

    print(*notes, sep='\n')
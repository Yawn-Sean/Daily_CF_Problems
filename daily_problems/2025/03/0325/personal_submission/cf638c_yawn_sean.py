# Submission link: https://codeforces.com/problemset/submission/1089/312129684#
def main():
    n = II()
    path = [[] for _ in range(n)]
    us = []
    vs = []

    for i in range(n - 1):
        u, v = GMI()
        path[u].append(i)
        path[v].append(i)
        us.append(u)
        vs.append(v)

    col = [-1] * (n - 1)
    stk = [0]

    while stk:
        u = stk.pop()
        used = -1
        for eid in path[u]:
            if col[eid] != -1:
                used = col[eid]
        
        cur = 0
        for eid in path[u]:
            if col[eid] == -1:
                while cur == used:
                    cur += 1
                col[eid] = cur
                cur += 1
                stk.append(us[eid] + vs[eid] - u)

    ans = max(col) + 1

    tmp = [[] for _ in range(ans)]
    for i in range(n - 1):
        tmp[col[i]].append(i)

    print(ans)

    outs = []
    for i in range(ans):
        outs.append(f'{len(tmp[i])} {" ".join(str(x + 1) for x in tmp[i])}')

    print('\n'.join(outs))
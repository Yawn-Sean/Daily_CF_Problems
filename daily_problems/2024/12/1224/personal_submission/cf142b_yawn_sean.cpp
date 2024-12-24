# Submission link: https://codeforces.com/contest/228/submission/298120972
def main():
    n, m = MII()
    path = [[] for _ in range(n)]

    for _ in range(m):
        u, v, w = MII()
        u -= 1
        v -= 1
        if w:
            path[u].append(v)
            path[v].append(u)
        else:
            path[u].append(~v)
            path[v].append(~u)

    cols = [-1] * n
    for i in range(n):
        if cols[i] == -1:
            cols[i] = 0
            stk = [i]
            while stk:
                u = stk.pop()
                for v in path[u]:
                    if v >= 0:
                        if cols[v] == -1:
                            cols[v] = cols[u]
                            stk.append(v)
                        elif cols[v] != cols[u]:
                            exit(print('Impossible'))
                    else:
                        v = ~v
                        if cols[v] == -1:
                            cols[v] = cols[u] ^ 1
                            stk.append(v)
                        elif cols[v] == cols[u]:
                            exit(print('Impossible'))

    print(sum(cols))
    print(' '.join(str(i + 1) for i in range(n) if cols[i]))
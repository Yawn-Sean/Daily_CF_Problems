# Submission link: https://codeforces.com/contest/1949/submission/264068597
def main():
    n = II()
    xs = []
    ys = []
    rs = []

    for _ in range(n):
        x, y, r = MII()
        xs.append(x)
        ys.append(y)
        rs.append(r)

    path = [[] for _ in range(n)]
    for i in range(n):
        for j in range(i):
            dx = xs[i] - xs[j]
            dy = ys[i] - ys[j]
            totr = rs[i] + rs[j]
            if dx * dx + dy * dy == totr * totr:
                path[i].append(j)
                path[j].append(i)

    col = [-1] * n
    flg = False

    for i in range(n):
        if col[i] == -1:
            f = True
            col[i] = 0
            c0, c1 = 1, 0
            stack = [i]
            while stack:
                u = stack.pop()
                for v in path[u]:
                    if col[v] == -1:
                        col[v] = col[u] ^ 1
                        if col[v]: c1 += 1
                        else: c0 += 1
                        stack.append(v)
                    elif col[v] ^ col[u] != 1:
                        f = False
            if f and c0 != c1:
                flg = True
                break

    print('YES' if flg else 'NO')
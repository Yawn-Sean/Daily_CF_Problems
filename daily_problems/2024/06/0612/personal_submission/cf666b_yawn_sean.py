# Submission link: https://codeforces.com/contest/666/submission/265426283
def main():
    n, m = MII()
    path = [[] for _ in range(n)]
    rev_path = [[] for _ in range(n)]

    for _ in range(m):
        u, v = GMI()
        path[u].append(v)
        rev_path[v].append(u)

    def f(x, y):
        return x * n + y

    dist = [-1] * (n * n)
    rev_dist = [-1] * (n * n)

    q = [0] * n
    for i in range(n):
        dist[f(i, i)] = 0
        q[0] = i
        l, r = 0, 1
        while l < r:
            u = q[l]
            l += 1
            for v in path[u]:
                if dist[f(i, v)] == -1:
                    dist[f(i, v)] = dist[f(i, u)] + 1
                    q[r] = v
                    r += 1
        
        rev_dist[f(i, i)] = 0
        q[0] = i
        l, r = 0, 1
        while l < r:
            u = q[l]
            l += 1
            for v in rev_path[u]:
                if rev_dist[f(i, v)] == -1:
                    rev_dist[f(i, v)] = rev_dist[f(i, u)] + 1
                    q[r] = v
                    r += 1

    ma = [[-1] * n for _ in range(3)]

    for i in range(n):
        for j in range(n):
            if dist[f(i, j)] > 0:
                if ma[0][i] == -1 or dist[f(i, j)] >= dist[f(i, ma[0][i])]:
                    ma[0][i], ma[1][i], ma[2][i] = j, ma[0][i], ma[1][i]
                elif ma[1][i] == -1 or dist[f(i, j)] >= dist[f(i, ma[1][i])]:
                    ma[1][i], ma[2][i] = j, ma[1][i]
                elif ma[2][i] == -1 or dist[f(i, j)] >= dist[f(i, ma[2][i])]:
                    ma[2][i] = j

    rev_ma = [[-1] * n for _ in range(3)]

    for i in range(n):
        for j in range(n):
            if rev_dist[f(i, j)] > 0:
                if rev_ma[0][i] == -1 or rev_dist[f(i, j)] >= rev_dist[f(i, rev_ma[0][i])]:
                    rev_ma[0][i], rev_ma[1][i], rev_ma[2][i] = j, rev_ma[0][i], rev_ma[1][i]
                elif rev_ma[1][i] == -1 or rev_dist[f(i, j)] >= rev_dist[f(i, rev_ma[1][i])]:
                    rev_ma[1][i], rev_ma[2][i] = j, rev_ma[1][i]
                elif rev_ma[2][i] == -1 or rev_dist[f(i, j)] >= rev_dist[f(i, rev_ma[2][i])]:
                    rev_ma[2][i] = j

    ans = 0
    chosen = []
    for b in range(n):
        for c in range(n):
            if b != c and dist[f(b, c)] > 0:
                for bi in range(3):
                    a = rev_ma[bi][b]
                    if a != -1 and a != b and a != c:
                        for ci in range(3):
                            d = ma[ci][c]
                            if d != -1 and d != a and d != b and d != c:
                                res = dist[f(a, b)] + dist[f(b, c)] + dist[f(c, d)]
                                if res > ans:
                                    ans = res
                                    chosen = [a, b, c, d]

    print(' '.join(str(x + 1) for x in chosen))
# Submission link: https://codeforces.com/contest/765/submission/257916128
def main():
    n = II()
    f = LGMI()

    fix_points = []
    for i in range(n):
        if f[f[i]] != f[i]:
            print(-1)
            exit()
        if f[i] == i:
            fix_points.append(i)

    m = len(fix_points)
    g = [0] * n
    h = [0] * m

    d = {v: i for i, v in enumerate(fix_points)}

    for i in range(n):
        g[i] = d[f[i]]
        if f[i] == i:
            h[g[i]] = i

    print(m)
    print(' '.join(str(x + 1) for x in g))
    print(' '.join(str(x + 1) for x in h))
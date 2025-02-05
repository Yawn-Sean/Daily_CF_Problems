# Submission link: https://codeforces.com/contest/853/submission/303310457
def main():
    n, m, k = MII()

    froms = [[] for _ in range(n + 1)]
    tos = [[] for _ in range(n + 1)]

    for _ in range(m):
        d, f, t, c = MII()
        if f: froms[f].append((d, c))
        else: tos[t].append((d, c))

    inf = 10 ** 13
    M = 10 ** 6
    ans1 = [0] * (M + 2)
    ans2 = [0] * (M + 2)

    for i in range(1, n + 1):
        froms[i].sort()
        tos[i].sort()
        
        fk = len(froms[i])
        tk = len(tos[i])
        
        if fk == 0 or tk == 0:
            exit(print(-1))
        
        ans1[0] += inf
        ans1[froms[i][0][0]] -= inf
        
        v = inf
        for j in range(fk - 1):
            v = fmin(v, froms[i][j][1])
            ans1[froms[i][j][0]] += v
            ans1[froms[i][j + 1][0]] -= v
        
        v = fmin(v, froms[i][-1][1])
        ans1[froms[i][-1][0]] += v
        ans1[-1] -= v
        
        ans2[tos[i][-1][0] + 1] += inf
        ans2[-1] -= inf
        
        v = inf
        for j in range(tk - 2, -1, -1):
            v = fmin(v, tos[i][j + 1][1])
            ans2[tos[i][j][0] + 1] += v
            ans2[tos[i][j + 1][0] + 1] -= v
        
        v = fmin(v, tos[i][0][1])
        ans2[0] += v
        ans2[tos[i][0][0] + 1] -= v

    for i in range(M + 1):
        ans1[i + 1] += ans1[i]
        ans2[i + 1] += ans2[i]

    ans = inf
    for i in range(M + 2):
        if i + k + 1 <= M:
            ans = fmin(ans, ans1[i] + ans2[i + k + 1])

    print(ans if ans < inf else -1)
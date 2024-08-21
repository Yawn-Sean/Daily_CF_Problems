# Submission link: https://codeforces.com/contest/1644/submission/277454886
def main():
    t = II()
    outs = []
    mod = 998244353
    vis1 = [0] * (2 * 10 ** 5)
    vis2 = [0] * (2 * 10 ** 5)

    for _ in range(t):
        n, m, k, q = MII()
        xs = []
        ys = []
        for _ in range(q):
            x, y = GMI()
            xs.append(x)
            ys.append(y)
        
        c1 = c2 = 0
        ans = 1
        for i in range(q - 1, -1, -1):
            if (not vis1[xs[i]] and c2 != m) or (not vis2[ys[i]] and c1 != n):
                ans = ans * k % mod
                if not vis1[xs[i]]:
                    vis1[xs[i]] = 1
                    c1 += 1
                if not vis2[ys[i]]:
                    vis2[ys[i]] = 1
                    c2 += 1
        
        for i in range(q):
            vis1[xs[i]] = 0
            vis2[ys[i]] = 0
        outs.append(ans)

    print('\n'.join(map(str, outs)))
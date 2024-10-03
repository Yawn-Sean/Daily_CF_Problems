# Submission link: https://codeforces.com/contest/1472/submission/284101060
def main():
    t = II()
    outs = []

    for _ in range(t):
        n = II()
        
        xs = []
        ys = []
        
        for _ in range(n):
            x, y = MII()
            if x > y: x, y = y, x
            xs.append(x)
            ys.append(y)
        
        ans = [-2] * n
        cur = 10 ** 9 + 1
        idx = -1
        for i in sorted(range(n), key=lambda i: xs[i] * 10 ** 9 - ys[i]):
            if ys[i] > cur:
                ans[i] = idx
            else:
                cur = ys[i]
                idx = i
        
        outs.append(' '.join(str(x + 1) for x in ans))

    print('\n'.join(outs))
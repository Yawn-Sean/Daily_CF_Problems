# Submission link: https://codeforces.com/contest/30/submission/326588748
def main():
    n = II()
    xs = []
    ys = []
    ts = []
    ps = []

    for _ in range(n):
        x, y, t, p = LI()
        x = int(x)
        y = int(y)
        t = int(t)
        p = float(p)
        xs.append(x)
        ys.append(y)
        ts.append(t)
        ps.append(p)

    st_range = sorted(range(n), key=lambda x: ts[x])
    dp = [0] * n

    for i in range(n):
        i1 = st_range[i]
        
        x1 = xs[i1]
        y1 = ys[i1]
        t1 = ts[i1]
        p1 = ps[i1]
        
        for j in range(i):
            i2 = st_range[j]
            
            x2 = xs[i2]
            y2 = ys[i2]
            t2 = ts[i2]
            p2 = ps[i2]
            
            if (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) <= (t2 - t1) * (t2 - t1):
                dp[i1] = fmax(dp[i1], dp[i2])
        
        dp[i1] += p1

    print(max(dp))
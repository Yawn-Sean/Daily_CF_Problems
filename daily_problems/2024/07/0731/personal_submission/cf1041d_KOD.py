    n, y = il()
    ad = []
    for i in range(n):
        a, b = il()
        ad += (a,b)
    ad = ad + [inf]
    s = []
    for i in range(0, n * 2, 2):
        s += (ad[i+1] - ad[i], ad[i+2] - ad[i + 1]),
    l = ans = t = 0
    h = y
    for r, (ad, sb) in enumerate(s):
        t += ad
        y -= sb
        ans = max(ans, t)
        while y <= 0:
            y += s[l][1]
            t -= s[l][0]
            l += 1
    print(ans + h)

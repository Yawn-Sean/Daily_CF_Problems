    n = ix()
    if n > 33: print(0)
    else:
        pts = []
        for i in range(n):
            pts += [il()]
        out = []
        for i in range(n):
            flg = True
            for j in range(n):
                for k in range(j):
                    cur = 0
                    for d in range(5):
                        cur += (pts[k][d] - pts[i][d]) * (pts[j][d] - pts[i][d])
                    if cur > 0:
                        flg = False
            if flg: out += i + 1,
        print(len(out))
        pl(out)

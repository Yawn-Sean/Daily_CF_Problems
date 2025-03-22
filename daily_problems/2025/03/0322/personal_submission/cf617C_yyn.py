def main():
    n,x1,y1,x2,y2 = MII()
    g = [[x1,y1]]
    for i in range(n):
        a,b = MII()
        g.append([a,b])
    g = sorted(g,key = lambda x:-((x[0] - x1) ** 2 + (x[1] - y1) ** 2))
    r2 = 0
    ans = inf
    for x,y in g:
        r1 = (x - x1) ** 2 + (y - y1) ** 2
        ans = min(ans,r1 + r2)
        r2 = max(r2,(x - x2) ** 2 +(y - y2) ** 2)

    print(ans)

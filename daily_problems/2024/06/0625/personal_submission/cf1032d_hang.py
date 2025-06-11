def  main():
    a,b,c = map(int,input().split())
    x1,y1,x2,y2 = map(int,input().split())
    def dist(x1,y1,x2,y2):
        return ((x1-x2)**2+(y1-y2)**2)**0.5
    def points(x, y):
        r = []
        if a:
            r.append((-(b * y + c) / a, y))
        if b:
            r.append((x, -(a * x + c) / b))
        return r
    ans = abs(x1-x2) + abs(y1-y2)
    for px1,py1 in points(x1,y1):
        for px2,py2 in points(x2,y2):
            ans = min(ans,dist(px1,py1,x1,y1)+dist(px2,py2,x2,y2)+ dist(px1,py1,px2,py2))
    print(ans)

main()
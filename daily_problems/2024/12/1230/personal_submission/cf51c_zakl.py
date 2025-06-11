def solve():
    n=_n()
    xs=sorted(_nA())
    def check(p):
        ed=xs[0]+2*p
        ret=1
        for i in xs:
            if i>ed:
                ret+=1
                ed=i+2*p
        return ret<=3
    l,r=0.0,xs[-1]-xs[0]
    while r-l>0.000001:
        mid = (l+r)/2
        if check(mid):
            r=mid
        else:
            l=mid
    
    def fk(x):
        return math.ceil(x*100000)/100000
    l=fk(l)
    print(f"{l:.6f}")
    ed=round(xs[0]+2*l,6)
    ret=[f"{fk((xs[0]+ed)/2):.6f}"]
    for i in xs:
        if i>ed:
            ed=round(i+2*l,6)
            ret.append(f"{fk((i+ed)/2):.6f}")
    while len(ret)<3:
        ret.append(ret[-1])
    print(*ret)
solve()


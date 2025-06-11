def solve():
    n,m,x,y,a,b=MIIS()
    g=gcd(a,b)
    a//=g;b//=g
    d=min(n//a,m//b)
    A=a*d;B=b*d
    x2=max(A,min(n,x+A//2))
    x1=x2-A
    y2=max(B,min(m,y+B//2))
    y1=y2-B
    print(x1,y1,x2,y2)
    return

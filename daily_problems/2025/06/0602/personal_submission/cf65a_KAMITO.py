def solve():
    a,b,c,d,e,f=MII()
    ok=True
    if d==0:
        ok=False
    elif c==0:
        ok=True
    elif b==0:
        ok=False
    elif a==0:
        ok=True
    elif b*d*f>a*c*e:
        ok=True
    else:
        ok=False
    print('Ron' if ok else 'Hermione')
    return

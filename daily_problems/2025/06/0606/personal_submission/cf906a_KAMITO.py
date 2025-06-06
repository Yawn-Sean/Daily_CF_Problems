def solve():
    n=II()
    s=set()
    for i in range(26):
        s.add(chr(ord('a')+i))
    ok=False
    ans=0
    for i in range(n):
        x,y=IS()
        if x=='!':
            s&=set(y)
            if ok:
                ans+=1
        elif x=='.':
            s-=set(y)
        else:
            if ok:
                if y not in s:
                    ans+=1
            else:
                s-=set(y)
        if len(s)==1:
            ok=True
    print(ans)
    return

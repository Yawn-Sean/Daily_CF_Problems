def solve():
    n,k=MIIS()
    q=LMIIS()
    for i in range(n):
        q[i]-=1
    s=LMIIS()
    for i in range(n):
        s[i]-=1
    p=[i for i in range(n)]
    if p==s:
        if k==0:
            print('YES')
        else:
            print('NO')
        return
    def act1(p):
        t=[0]*n
        for j in range(n):
            t[j]=p[q[j]]
        return t
    def act2(p):
        t=[0]*n
        for j in range(n):
            t[q[j]]=p[j]
        return t
    for i in range(k):
        p=act1(p)
        if p==s:
            if i==k-1:
                print('YES')
                return
            else:
                p=act2(p)
                p=act2(p)
                if p==s:
                    print('NO')
                    return
    p=[i for i in range(n)]
    for i in range(k):
        p=act2(p)
        if p==s:
            if i==k-1:
                print('YES')
                return
            else:
                p=act1(p)
                p=act1(p)
                if p==s:
                    print('NO')
                    return
    print('NO')
    return

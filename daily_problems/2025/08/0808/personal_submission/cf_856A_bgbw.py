t=II()
maxsize =10**6+1
c = [1] * maxsize
for _ in range  (t ):
    n=II()
    s=LII()
    ans =[]
    for i in range( 1,maxsize ):
        if c[i]:
            for j in range ( n):
                for k in range (j ):
                    cur =i+abs(s[k]-s[j])
                    if cur <maxsize :
                        c[cur ]=0
            ans.append( i )
            if len(ans )==n:
                break
    for i in range (1,maxsize):c[i]=1
    print('YES')
    print(*ans )

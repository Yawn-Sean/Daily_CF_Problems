n=II()
a=[]
b =[]
c=[]
for i in range(n):
    q,w,e=MII()
    a.append(q)
    b.append(w)
    c.append( e )
ans= math.inf
def f (x, y ):
    return math.hypot(a[x ]-a[y],b[ x ]-b [y],c[x ]- c[y  ] )
for i in range(1,n):
    for j in range(i+1,n):
        cur =f(0,i)+f(0,j)+f(i,j)
        if cur <ans :
            ans =cur
        # ans =min(ans,))
print(ans /2)

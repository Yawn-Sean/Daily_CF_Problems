
n,m=MII()
s=LII()
t=m
s.sort( reverse= True )
ans =[]
if m<=n:
    for i in range( m ):ans.append ([s[i]])

else:
    m-=n
    for i in range(n): ans.append([s[i]])
    for i in range ( 2, n +1):
        cur=s[:i-1]
        for j in range(i-1,n):
            ans.append( cur+[s[j]])
            m-=1
            if not m:
                break
        if not m:break
for i in range(t):
    print("{} {}".format( len(ans[i]),' '.join(map(str,ans[i]))))

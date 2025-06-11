n,m=map(int,input().split())
ans=0
for i in range(1,m+1):
    x=(n-i+m)//m
    for j in range(1,m+1):
        y=(n-j+m)//m
        if (i*i+j*j)%m==0:
            ans+=x*y
print(ans)

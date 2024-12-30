n=int(input())
a=list(map(int,input().split()))
b=[0]*(n+1)
k=0
for i in a:
    b[i]=k
    k+=1
p=[False]*(n+1)
for i in range(n,0,-1):
    k=1
    while b[i]+k*i<n or b[i]-k*i>=0:
        if b[i]-k*i>=0:
            tar=a[b[i]-k*i]
            if tar>i and p[tar]==False:
                p[i]=True
                break
        if b[i]+k*i<n:
            tar=a[b[i]+k*i]
            if tar>i and p[tar]==False:
                p[i]=True
                break
        k+=1
ans=[]
for i in a:
    if p[i]:
        ans.append("A")
    else:
        ans.append('B')
print(''.join(ans))

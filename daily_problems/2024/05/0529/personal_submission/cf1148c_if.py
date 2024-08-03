n=int(input())
a=list(map(int,input().split()))
ans=[]
left=n//2
right=n//2+1
a.insert(0,0)
def check(i):
    while i<=n:
        if a[i] in [1,n,i]:
            i+=1
            continue
        if a[i]!=i:
            if abs(a[i]-i)>=n//2:
                ans.append([a[i],i])
                k1=a[i]
                k2=a[a[i]]
                a[a[i]]=k1
                a[i]=k2
                continue
            elif i<=left:
                ans.append([i,n])
                a[i],a[n]=a[n],a[i]
                if a[n]<=left:
                    ans.append([n,a[n]])
                    k1=a[n]
                    k2=a[a[n]]
                    a[a[n]]=k1
                    a[n]=k2
                    
                    continue
                else:
                    ans.append([1,n])
                    a[1],a[n]=a[n],a[1]
                    ans.append([1,a[1]])
                    k1=a[1]
                    k2=a[a[1]]
                    a[a[1]]=k1
                    a[1]=k2
                    continue
            else:
                ans.append([i,1])
                a[i],a[1]=a[1],a[i]
                if a[1]>=right:
                    ans.append([1,a[1]])
                    k1=a[1]
                    k2=a[a[1]]
                    a[a[1]]=k1
                    a[1]=k2
                    continue
                else:
                    ans.append([1,n])
                    a[1],a[n]=a[n],a[1]
                    ans.append([n,a[n]])
                    k1=a[n]
                    k2=a[a[n]]
                    a[a[n]]=k1
                    a[n]=k2
                    continue
            i+=1
check(1)
check(1)
if a[1]!=1:
    ans.append([1,n])
print(len(ans))
for i in ans:
    print(*i)

n,m=map(int,input().split())
a=list(map(int,input().split()))
left=0
right=m-1
while left<right:
    mid=(left+right)//2
    u=True
    if a[0]+mid>=m:
        pre=0
    else:
        pre=a[0]
    for i in range(1,n):
        if a[i]==pre:
            continue
        elif a[i]<pre:
            if a[i]+mid<pre:
                u=False
                break
            else:
                continue
        else:
            if a[i]+mid>=m:
                if (a[i]+mid)%m>=pre:
                    continue
                else:
                    pre=a[i]
            else:
                pre=a[i]
    if u:
        right=mid
    else:
        left=mid+1
print(left

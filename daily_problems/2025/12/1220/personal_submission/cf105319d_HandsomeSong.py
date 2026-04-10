def II():
    return int(input())
def LII():
    return list(map(int, input().split()))

n=II()
a=LII()
l,r=0,0
ans=0
c0=[0]*30
c1=[0]*30
while l<n:
    while r+1<n:
        v=(a[r]^a[r+1]).bit_length()-1
        if v>=0:
            if a[r]>>v&1:
                if c0[v]:
                    break
                c1[v]+=1
            else:
                if c1[v]:
                    break
                c0[v]+=1
        r+=1
    ans+=r-l+1
    if l+1<n:
        v=(a[l]^a[l+1]).bit_length()-1
        if v>=0:
            if a[l]>>v&1:
                c1[v]-=1
            else:
                c0[v]-=1
    l+=1
print(ans)
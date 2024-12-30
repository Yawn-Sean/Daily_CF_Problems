n=int(input())
u=list(map(int,input().split()))
a=[0]*(10**5+1)
cnt=[0]*(n+1)
ans=0
m=0
for s,i in enumerate(u,1):
    if cnt[a[i]]:
        cnt[a[i]]-=1
    a[i]+=1
    cnt[a[i]]+=1
    m=max(m,a[i])
    if m==1 or cnt[s]==1:
        ans=s
        continue
    if m*cnt[m]==s-1 or (m-1)*(cnt[m-1]+1)+1==s:
        ans=s
        continue
print(ans)

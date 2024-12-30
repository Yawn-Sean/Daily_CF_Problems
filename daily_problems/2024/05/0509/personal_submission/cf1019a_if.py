from collections import Counter
n,m=map(int,input().split())
ll=[]
cnt1=Counter()
for _ in range(n):
    p,c=map(int,input().split())
    cnt1[p]+=1
    if p!=1:    
        ll.append([p,c])
ll.sort(key=lambda x:x[1])
k=len(ll)
ans=float("inf")
for x in range(n):
    l=[i.copy() for i in ll]
    cost=0
    cnt=cnt1.copy()
    cur=cnt[1]
    for i in range(k):
        if cnt[l[i][0]]>=x:
            cnt[l[i][0]]-=1
            cost+=l[i][1]
            cur+=1
            l[i][0]=0
    j=0
    while cur<x and j<k:
        if l[j][0]:
            cost+=l[j][1]
            cur+=1
        j+=1
    if cost<ans:
        ans=cost
print(ans)

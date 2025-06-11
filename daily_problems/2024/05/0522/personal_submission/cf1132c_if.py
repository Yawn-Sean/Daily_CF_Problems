n,q=map(int,input().split())
s=[]
nums=[0]*n
for _ in range(q):
    l,r=map(int,input().split())
    l-=1
    r-=1
    s.append([l,r])
    nums[l]+=1
    if r+1<n:
        nums[r+1]-=1
cnt=9999999
oo=[0]
nu=nums.copy()
for i in range(1,n):
    nu[i]+=nu[i-1]
for i in nu:
    if i==1:
        oo.append(1)
    else:
        oo.append(0)
for i in range(1,len(oo)):
    oo[i]+=oo[i-1]
for i in range(q-1):
    ss1=oo[s[i][1]+1]-oo[s[i][0]]
    num=nums.copy()
    num[s[i][0]]-=1
    if s[i][1]+1<n:
        num[s[i][1]+1]+=1
    for w in range(1,n):
        num[w]+=num[w-1]
    o=[]
    for w in num:
        if w==1:
            o.append(1)
        else:
            o.append(0)
    for w in range(1,n):
        o[w]+=o[w-1]
    o=[0]+o
    for j in range(i+1,q):
        ss2=ss1+o[s[j][1]+1]-o[s[j][0]]
        cnt=min(cnt,ss2)
ans=0
for i in nu:
    if i:
        ans+=1
print(ans-cnt)

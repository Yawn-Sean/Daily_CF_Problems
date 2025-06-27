n=II()
path=defaultdict(list)
cnt=[0]*(n+1)
for i in range(n-2):
    s=LII()
    s.sort()
    a,b,c=s
    cnt[a]+=1
    cnt[b]+=1
    cnt[c]+=1
    path[(a,b)].append(c)
    path[(a,c)].append(b)
    path[(b,c )].append(a )
ans=[]
for i in range(1,n+1):
    if cnt[i]==1:
        ans.append(i)
        break
for i ,j in path:
    if i==ans[-1] and cnt[j]==2:
        ans.append(j)
        break
    if j == ans[-1] and cnt[i] == 2:
        ans.append(i)
        break

for i in range(n-2):
    a,b=ans[-2],ans[-1]
    if a>b:
        a,b=b,a
    for j in path[(a,b)]:
        if len(ans) ==2 or ans [-3]!=j:
            ans.append(j)
            break
print(' '.join(map(str,ans )))

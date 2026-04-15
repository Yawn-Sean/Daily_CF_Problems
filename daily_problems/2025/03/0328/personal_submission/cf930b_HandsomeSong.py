def I():
    return input().strip() 
s=I()
ls=[]
n=len(s)
for c in s:
    ls.append(ord(c)-97)
d=[[]for _ in range(26)]
for i in range(n):
    d[ls[i]].append(i)
ans=0
for i in range(26):
    res=0
    for p in range(n):
        cnt=[0]*26
        for x in d[i]:
            cnt[ls[(x+p)%n]]+=1
        res=max(res,sum(x==1 for x in cnt))
    ans+=res
print(ans/n)
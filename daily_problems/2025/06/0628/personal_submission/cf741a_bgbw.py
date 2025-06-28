n=II()
s=[0]+LII()
ans=[]
visit=[True]*(n+1)
for i in range(1,n+1):
    if visit[i]:
        cur=i
        visit[cur ]=False
        k=1
        while  visit[s[cur]]:
            cur=s[cur ]
            visit[cur ]=False
            k+=1
        if s[cur] !=i:
            exit(print(-1))
        else:
            ans .append(k)
q=1
for i in ans :
    if i%2:
        q=math.lcm(q,i)
    else:
        q=math.lcm(q,i//2)
print(q)

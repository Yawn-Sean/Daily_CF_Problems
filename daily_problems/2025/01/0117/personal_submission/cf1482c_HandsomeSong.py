import sys
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
t=II()
for _ in range(t):
    n,m=MII()
    ars=[None]*m
    for i in range(m):
        ars[i]=LII()
        k=ars[i].pop(0)
    cnt=[0]*(n+1)
    ans=[0]*m
    v=0
    for i in range(m):
        ans[i]=ars[i][0]
        cnt[ans[i]]+=1
        if cnt[ans[i]]>cnt[v]:
            v=ans[i]
    fre=m-m//2
    for i in range(m):
        if ans[i]==v and cnt[v]>fre and len(ars[i])>1:
            ans[i]=ars[i][1]
            cnt[v]-=1
    if cnt[v]>fre:
        print('NO')
    else:
        print('YES') 
        print(*ans) 
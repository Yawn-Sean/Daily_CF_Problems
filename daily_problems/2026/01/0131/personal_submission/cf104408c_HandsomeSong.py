def II():
    return int(input())
def MII():
    return map(int, input().split())
def LI():
    return list(input().split())
def LII():
    return list(map(int, input().split()))
def I():
    return list(input())
    
t=II()
for _ in range(t):
    n,m=MII()
    cnt=[0]*m
    for _ in range(n):
        s=input()
        if (s[m-1])=='1':
            cnt[m-1]+=1
        
        for i in range(m-1):
            if s[i]!=s[i+1]:
                cnt[i]+=1
    ans=0
    for i in range(m):
        ans+=min(cnt[i],n-cnt[i])
    print(ans)

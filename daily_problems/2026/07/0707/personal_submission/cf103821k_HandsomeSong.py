import sys
from collections import defaultdict
input=sys.stdin.readline
def II():
    return int(input())
def MII():
    return map(int,input().split())
mod=10**9+7
t=II()
for _ in range(t):
    n,m=MII()
    movies=[]
    for _ in range(n):
        l,r=MII()
        movies.append((l,r))
    movies.sort(key=lambda x:x[1])
    pref_end=[0]*(m+2)
    idx=0
    for time in range(1,m+1):
        while idx<n and movies[idx][1]==time:
            l,r=movies[idx]
            pref_end[time]=(pref_end[time]+l)%mod
            idx+=1
        pref_end[time]=(pref_end[time]+pref_end[time-1])%mod
    ans=0
    for l,r in movies:
        if l>1:
            ans=(ans+pref_end[l-1]*(m-r+1))%mod
    print(ans)

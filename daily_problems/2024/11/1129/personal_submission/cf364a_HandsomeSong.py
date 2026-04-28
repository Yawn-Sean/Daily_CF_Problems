import sys
from collections import Counter
input = sys.stdin.readline
def II():
    return int(input())
def I():
    return input().strip()
a=II()
s=[int(x) for x in I()]
n=len(s)
cnt=Counter()
for i in range(n):
    sm=0
    for j in range(i,n):
        sm+=s[j]
        cnt[sm]+=1
total=n*(n+1)//2
if a==0:
    ans=cnt[0]*total +(total-cnt[0])*cnt[0]
    print(ans)
else:
    ans=0
    for v in range(1,int(a**0.5)+1):
        if a%v==0:
            w=a//v
            if w in cnt:
                ans+=cnt[v]*cnt[w]
            if v !=w and v in cnt:
                ans+=cnt[v]*cnt[w]
    print(ans)
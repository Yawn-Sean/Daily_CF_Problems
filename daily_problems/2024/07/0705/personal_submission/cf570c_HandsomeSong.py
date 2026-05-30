import sys
input = sys.stdin.readline
def MII():
    return map(int, input().split())
def I():
    return input().strip()
n,m=MII()
cnt=0
s=list(I())
for i in range(n-1):
    if s[i]==s[i+1]=='.':
        cnt+=1
for _ in range(m):
    x,c=I().split()
    x=int(x)-1
    for j in (x-1,x):
        if 0<=j<n-1:
            if s[j]=='.'and s[j+1]=='.':
                cnt-=1
    s[x]=c
    for j in(x-1,x):
        if 0<=j<n-1:
            if s[j]=='.' and s[j+1]=='.':
                cnt+=1
    print(cnt)
from heapq import nlargest
def II():
    return int(input())
t=II()
for _ in range(t):
    n=II()
    s = [int(c) for c in input()]
    if n==1: 
        print(0,0)
    else:
        ans=sum(s)*11
        x,y=nlargest(2,s)
        ans-=x*10
        ans-=y
        cnt=0
        if s[0]!=y:
            cnt+=1
        if s[-1]!=x:
            cnt+=1
        if s[0]==x and s[-1]==y:
            cnt=min(cnt,1)
        print(cnt,ans)
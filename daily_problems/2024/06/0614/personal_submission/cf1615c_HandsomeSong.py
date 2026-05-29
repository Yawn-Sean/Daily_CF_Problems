import sys
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
def LI():
    return list(input().strip())
def I():
    return input().strip()
t=II()
for i in range(t):
    n=II()
    a=I()
    b=I()
    if a==b:
        print(0)
        continue
    a1=a.count('1')
    b1=b.count('1')
    diff=sum(1 for i in range(n) if a[i]!=b[i])
    same=n-diff
    ans=10**18
    if a1==b1:
        ans=min(ans,diff)
    if b1==n-a1+1:
        ans=min(ans,same)
    if ans==10**18:
        print(-1)
    else:
        print(ans)
import sys
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
t=II()
h=[0]*(2*10**5+5)
for i in range(1,2*10**5+5):
    h[i]=h[i-1]+1/i
for _ in range(t):
    n=II()
    a=LII()
    pre=[0]*(n+1)
    for i in range(n):
        pre[i+1]=pre[i]+a[i]
    N=n*(n+1)//2
    ans=0
    for i in range(1,n+1):
        diff=pre[i]-pre[n-i]
        ans+=diff*h[i]/N
    print(ans)
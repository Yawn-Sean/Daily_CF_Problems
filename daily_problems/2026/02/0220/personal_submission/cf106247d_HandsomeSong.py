import sys
input = sys.stdin.readline
def II():
    return int(input())
n=II()
k=II()
ans=n+1
for i in range(1,10**6+1):
    if n%i==0:
        if i<=k:
            ans=(max(ans,n+i))
        if n//i<k:
            ans=max(ans,n+n//i)
print(ans)
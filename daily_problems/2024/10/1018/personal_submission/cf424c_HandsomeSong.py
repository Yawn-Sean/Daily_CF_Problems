import sys
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
n=II()
a=LII()
ans=0
for x in a:
    ans^=x
pref=[0]*(n+1)
for i in range(1,n+1):
    pref[i]=pref[i-1]^i
for i in range(1,n+1):
    block=n//i
    rem=n%i
    if block%2:
        ans^=pref[i-1]
    ans^=pref[rem]
print(ans)
import sys
input = sys.stdin.readline
def II():
    return int(input())
def I():
    return input().strip()
n=II()
a=[int(cc) for cc in I()]
b=[int(cc) for cc in I()]
c=[int(cc) for cc in I()]
k=len(a)
ans=1
mod=10**9+7
saved=pow(2,n-1,mod)
for i in range(k):
    res=0
    if a[i]:
        if b[i]and n%2==c[i]:
            res=1
    else:
        if b[i]==0:
            if c[i]==0:
                res=1
        else:
            if n>=2:
                res=saved
                if c[i]==0:
                    res-=1
                    res%=mod
                if n%2==c[i]:
                    res-=1
                    res%=mod
    ans=ans*res%mod
print(ans)
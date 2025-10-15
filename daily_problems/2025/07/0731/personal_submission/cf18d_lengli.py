import sys
input = lambda: sys.stdin.readline().strip()

def solve():
    la=[-1]*2010
    n=int(input())
    f=[0]*(n+1)

    for i in range(1,n+1):
        s,x=input().split()
        x=int(x)
        f[i]=f[i-1]
        if s[0]=='w': la[x]=i-1
        else:
            if la[x]!=-1:
                f[i]=max(f[i],f[la[x]]+(1<<x))
    print(f[n])

solve()

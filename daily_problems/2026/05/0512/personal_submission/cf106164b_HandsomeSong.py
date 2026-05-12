import sys
input=sys.stdin.readline
def II():
    return int(input())
def MII():
    return map(int,input().split())
t=II()
for _ in range(t):
    n,m=MII()
    ans=[]
    if n==2:
        if m%2:
            print('2 1')
        else:
            print('1 2')
    else:
        m=min(n,m)
        for i in range(m):
            ans.append(str(n-i))
        for i in range(n-m):
            ans.append(str(i+1))
        print(' '.join(ans))
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
n,q=MII()
r=LII()
c=LII()
rs=[0]*n
seg=0
for i in range(1,n):
    if r[i]%2 !=r[i-1]%2:
        seg+=1
    rs[i]=seg
cs=[0]*n
seg=0
for i in range(1,n):
    if c[i]%2 !=c[i-1]%2:
        seg+=1
    cs[i]=seg
for _ in range(q):
    ra,ca,rb,cb=map(int,input().split())
    ra-=1
    rb-=1
    ca-=1
    cb-=1
    if rs[ra]==rs[rb] and cs[ca]==cs[cb]:
        print('YES')
    else:
        print('NO')
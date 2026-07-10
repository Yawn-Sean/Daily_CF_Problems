import sys
import math
input = sys.stdin.readline
def MII():
    return map(int, input().split())
l,r,x,y=MII()
if y%x:
    print(0)
    exit()
k=y//x
cnt=0
for m in range(1,int(math.isqrt(k))+1):
    if k%m==0:
        n=k//m
        if math.gcd(m,n)==1:
            a=x*m
            b=x*n
            if a>=l and a<=r and b>=l and b<=r:
                cnt+=2 if m!=n else 1
print(cnt)
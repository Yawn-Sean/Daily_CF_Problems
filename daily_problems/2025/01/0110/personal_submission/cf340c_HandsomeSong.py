from math import gcd
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
n=II()
a=LII()
a.sort()
sm=0
for i in range(n):
    sm+=a[i]*(2*i-n+1)
up=sum(a)+2*sm
down=n
g=gcd(up,down)
print(up//g,down//g)
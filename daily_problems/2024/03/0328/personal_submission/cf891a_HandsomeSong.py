from math import gcd 
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))

n=II()
a=LII()
if gcd(*a)!=1:
    print(-1)
    exit()
if 1 in a:
    print(n-a.count(1))
else:
    mn=n
    for i in range(n):
        g=a[i]
        for j in range(i,n):
            g=gcd(g,a[j])
            if g ==1:
                mn=min(mn,j-i)
                break
    print(mn+n-1)    
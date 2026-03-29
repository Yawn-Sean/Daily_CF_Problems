from math import sqrt
def MII():
    return map(int, input().split())
def LII():
    return list(map(int, input().split()))

n,r = MII()
a = LII()
pos=[r]*n
for i in range(n):
    for j in  range(i):
        if abs(a[i]-a[j])<=2*r:
            pos[i]=max(pos[i],pos[j]+sqrt(4*r*r-(a[i]-a[j])**2))
print(*pos)
import sys
input = sys.stdin.readline
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
n,l=MII()
x=LII()
x.sort()
for i in range(n):
    x.append(x[i]+l)
total=n*(n-1)*(n-2)//6
r=0
for i in range(n):
    while 2*(x[r]-x[i])<l:
        r+=1
    v=r-i-1
    total-=v*(v-1)//2
print(total)
import sys
input = sys.stdin.readline
def MII():
    return map(int, input().split())
x,y=MII()
a,b=y,y
cnt=2
while a<x:
    a,b=a+b-1,a
    cnt+=1
print(cnt)
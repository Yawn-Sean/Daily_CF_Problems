import sys
input = sys.stdin.readline
def II():
    return int(input())
def MII():
    return map(int, input().split())
n=II()
x1,x2=MII()
lines=[]
for _ in range(n):
    k,b=MII()
    lines.append((k*x1+b,k*x2+b))
lines.sort()
for i in range(n-1):
    if lines[i][1]>lines[i+1][1]:
        print('Yes')
        exit()
print('No')
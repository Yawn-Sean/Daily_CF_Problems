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
n=II()
a=LII()
b=LII()
m=II()
arr=a+b
arr.sort()
d=0
for i in range(n):
    if a[i]==b[i]:
        d+=1
ans=1
power=0
i=0
while i<2*n:
    j=i
    while j<2*n and arr[j]==arr[i]:
        j+=1
    c=j-i
    for k in range(1,c+1):
        x=k
        while x%2==0:
            x//=2
            power+=1
        ans=ans*x%m
    i=j
power-=d
print(ans*pow(2,power,m)%m)
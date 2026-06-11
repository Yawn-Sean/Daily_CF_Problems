import sys
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
n=II()
a=LII()
idc=[i for i,val in enumerate(a) if val!=0]
idc0=[i for i,val in enumerate(a) if val==0]
x=[0]*n
p=m=0
for i in idc0:
    x[i]=1<<p
    p+=1
m=0
for i in idc:
    val=1<<p
    x[i]=a[i]*val
    m+=val
    p+=1
print(m)
print(*x)
import sys
input=sys.stdin.readline
def II():
    return int(input())
def MII():
    return map(int,input().split())
t=II()
v1=[[] for _ in range(t)]
w1=[]
for i in range(t):
    k,*v1[i]=MII()
    w1.extend(v1[i])
v2=[[] for _ in range(t)]
w2=[]
for i in range(t):
    k,*v2[i]=MII()
    w2.extend(v2[i])
w1.sort()
w2.sort()
if w1!=w2: print('N')
elif t==1 or t >=3: print('S')
else:
    while v1[1]:
        v1[0].append(v1[1].pop())
    while v2[1]:
        v2[0].append(v2[1].pop())
    if v1[0]==v2[0]: 
        print('S')
    else: print('N')
import sys
from collections import Counter
input=sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
n=II()
p=LII()
q=[p-1 for p in p]
qinv=[0]*n
for i in range(n):
    qinv[q[i]]=i
count=Counter()
for j in range(n):
    count[(q[j]+j) % n]+=1
total=0
for x in range(n):
    target=(x+qinv[x]) % n
    total+=count[target]
print(total)

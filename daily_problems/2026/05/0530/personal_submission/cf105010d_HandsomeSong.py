import sys
input = sys.stdin.readline
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
n,k=MII()
a=LII()
c=0
for x in a:
    if x%k:
        c+=1
if c==0:
    print('Rami')
elif c==2:
    print('Oussama')
else:
    print('Oussama'if n%2==0 else 'Rami')
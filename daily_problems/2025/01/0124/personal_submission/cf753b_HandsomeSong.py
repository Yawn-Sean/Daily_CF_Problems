import sys
from itertools import permutations
input = sys.stdin.readline
def MII():
    return map(int, input().split())
def ask(s):
    print(s,flush=True)
    x,y=MII()
    if x==4:
        exit()
    return x,y
num=[]
for i in range(10):
    x,y=ask(str(i)*4)
    if x+y>0:
        num.append(str(i))
for p in permutations(num):
    ask(''.join(p))
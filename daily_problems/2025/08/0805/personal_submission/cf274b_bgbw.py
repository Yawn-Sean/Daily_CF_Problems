import math
from bisect import bisect_left, bisect_right
from functools import lru_cache, reduce
from itertools import accumulate
from math import inf
import sys
from collections import Counter, deque, defaultdict
import heapq
from operator import xor, or_

List = list


# max=lambda  x,y :x if x >y  else y
# min=lambda  x,y :x if x <y  else y
def MII():
    return map(int, sys.stdin.readline().split())


def MFI():
    return map(float, sys.stdin.readline().split())


def IS():
    return sys.stdin.readline().split()


def II():
    return int(sys.stdin.readline())


def LII():
    return list(MII())


def LFI():
    return list(MFI())


def I():
    return sys.stdin.readline().strip()
n=II()
path=[[] for i in range( n )]
for i in range(n-1):
    a,b=MII()
    a-=1
    b-=1
    path [a ].append( b )
    path [b  ].append(  a )
s=LII()
a=  [0] * n
b=[0] * n
c=[(0,-1)]
for i ,k in c :
    for j in path [i]:
        if j!=k:
            c.append( (j,i) )
while  c :
    x,y =c.pop( )
    for i in path [x ]:
        if i!=y :
            a[x] = max(a[x], a[i])
            b[x] = max(b[x], b[i])
        cur = a[x] - b[x]
        if s[x] > cur:
            a[x] += s[x] - cur
        else:
            if s[x] < cur: b[x] += cur - s[x]
print( a[0]+b[0])

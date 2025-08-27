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


# min=lambda  x,y :x if x <y  else y
max=lambda  x,y :x if x >y  else y
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
n,m=MII()
s=[LII()[1:] for i in range  ( n )]
a=[ sum(s[i ]) for i in range( n )]
b=[]
c=[]
d=[]
e=LII()
for i in range( n ):
    cur =0
    ans =-inf
    for j in range(len(s[i])):
        cur+=s[i][j]
        ans = max(ans, cur)
        cur =max(cur ,0)

    c.append( ans )
for i in range( n ):
    cur =0
    ans =-inf
    for j in range(len(s[i])):
        cur =cur +s[i][j ]
        ans=max(ans ,cur )
    b.append( ans )
for i in range( n ):
    cur =0
    ans =-inf
    for j in range(len(s[i])-1,-1,-1):
        cur +=s[i ][ j ]
        ans=max(ans ,cur )
    d.append( ans )
ans =-inf
cur =0
for i in range( m ):
    tem =e[i]-1
    ans=max(ans,cur +b[tem ])
    ans=max(ans,c[tem])
    cur =max(cur +a[tem  ],d[tem])
print(ans )

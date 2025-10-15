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
a=LII()
b=LII()
c={}
for i in range ( n ):
    c[a[i]]= i
d=[ ]
for i in range( n ):
    d.append( c[b[i]])
dp=[]
cur =deque ()
# print(d )
def find_right (dp,cur  ,x ):
    q  =bisect_left(   cur   ,x )
    dp[len(dp)-q  ]= x
    cur [q-1 ]=x
for i in range( n ):
    if not dp or  dp[-1]>d[i]:
        dp.append( d[i ])
        cur.appendleft( d[i ])
    else:
        find_right( dp,cur ,d[i])
print(len(dp))

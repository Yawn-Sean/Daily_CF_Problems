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
n,m=MII()
ans =[ 0] * 9
a=[[] for i in range ( n )]
b=[[] for i in range ( n )]
c =[[] for i in range (2* n )]
d =[[] for i in range ( 2*n)]
# zero=n-1
cur =[0] * m
for i in range ( m ):
    x,y =MII()
    x-=1
    y-=1
    a[x ].append( (y,i ))
    b[y  ].append( (x,i ))
    c[x-y].append( (x,i) )
    d[y+x   ].append( (x,i) )
for i in range ( n ):
    if len(a[i])>=2 :
        a[i].sort( )
        cur [a[i][0][1]]+=1
        cur [a[i][-1][1]]+=1
        for j in a[i][1:-1]:cur[j[1]]+=2
    if len(b[i] )>=2 :
        b[i].sort( )
        cur [b[i][0][1]]+=1
        cur [b[i][-1][1]]+=1
        for j in b[i][1:-1]:cur [j[1]]+=2

for i in range(2*n):
    if len(c[i])>=2 :
        c[i].sort( )
        cur [c[i][0][1]]+=1
        cur [c[i][-1][1]]+=1
        for  j in c[i][1:-1]:cur[j[1]]+=2
    if len(d[i]) >= 2:
        d[i].sort()
        cur[d[i][0][1]] += 1
        cur[d[i][-1][1]] += 1
        for j in d[i][1:-1]: cur[j[1]] += 2
for i in range(m):
    ans[cur [i]]+=1
print( *ans )

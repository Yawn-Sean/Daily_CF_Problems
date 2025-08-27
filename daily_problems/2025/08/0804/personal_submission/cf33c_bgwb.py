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
s=LII()
if n==1:
    print(abs(s[0]))
    exit()
a= [0] * n
b = [0] * n
a[-1]=abs(s[-1])
c=list(accumulate (s ))
b[0]=abs(s[0])
c.append(0)
for i in range ( n-2,-1,-1 ):
    a[i ]=max(a[i+1]+s[i ],c[i-1]-c[-2 ] )
for i in range( 1,  n):
    b[i]=max(b[i-1]+s[i ],-c[i ])

ans =max(a[i]+b[i-1 ] for i in range ( 1,n ))
ans=max(a[0],b[-1],ans )
# print(a)
# print(b)
print(ans )

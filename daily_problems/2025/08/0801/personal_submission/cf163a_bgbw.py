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
a=I()
b=I()
mod =10**9+7
n,m=len(a ),len(b )
dp  =[[0] * (m +1 )  for i in range ( n+1 )]
ans =0
for i in range (1,n +1):
    for j in range( 1,m+1 ):
        dp[i][j] = dp[i][j - 1]
        if a[i-1]==b[j-1]:
            dp[ i ][ j ]+=dp[ i -1][ j -1]+1
            dp[ i ][j]%=mod
    ans+=dp[ i ][ -1 ]
    ans%=mod
print(ans )

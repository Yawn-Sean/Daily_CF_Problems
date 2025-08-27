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
maxsize =n +1
q=[0]*maxsize
prime=[1 ]
for i in range ( 2,maxsize ):
    if not q[i]:
        for j in range ( i*2 , maxsize ,i ):
            if not q[j]:
                q[j]=i
        prime.append( i )
l=len(prime )
c=[-1]* l
def find(x ):return  bisect_left( prime,x )
for  _ in range( m ):
    a,b=IS ()
    b=int( b )
    cur =b
    if a=='-':
        if q[cur ]:
            if c[find( q[cur] )] !=b :
                print('Already off')
            else:
                while  q[cur] :
                    c[find( q[cur] )]=-1
                    cur = cur // q[cur]
                c[find( cur )]=-1
                print('Success')
        else:
            if c[find(cur)] != b:
                print('Already off')
            else:
                c[find(cur)] = -1
                print('Success')
    else:
        flag = 0
        while q[ cur] :
            if c[find( q[cur] )]!=-1:
                if c[find( q[cur] )]==b :
                    print('Already on')
                else:
                    print('Conflict with {}'.format( c[find( q[cur] )]))
                flag= 1
                break
            cur = cur // q[cur]
        if not flag:
            if c[find(cur )] != -1:
                if c[find(cur )] == b:
                    print('Already on')
                else:
                    print('Conflict with {}'.format(c[find(cur) ]))
                flag = 1
        if not flag:
            cur = b
            while q[cur]:
                c[find(q[cur])] = b
                cur =cur // q[cur ]
            c[find( cur )]=b
            print('Success')


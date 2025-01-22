from cmath import inf
from collections import defaultdict, deque
import sys
import os, sys
from io import BytesIO, IOBase
 


import io
import sys
import time

def _n():
    return int(input())


def _nA():
    return list(map(int, input().split()))


def _nS():
    return input().split()



# @debug(data=input_data)
def solve():
    n = _n()
    arr = _nA()
    zc=nc=0
    x=[]
    for i in range(n):
        if arr[i]<0:
            nc+=1
        elif arr[i]==0:
            zc+=1
        x.append((i+1,arr[i]))
    x.sort(key=lambda x:(abs(x[1]),x[0]))
    hpos= x[-2][0] if nc==1 and x[-1][1]<0 else x[-1][0]
    ret=[]
    pnc,pzc,i=nc,zc,n-1
    while i>=0:
        p,v=x[i]
        i-=1
        if v<0:
            if pnc%2:
                if nc==1:
                    if zc:
                        ret.append(f'1 {p} {x[0][0]}')
                    else:
                        ret.append(f'2 {p}')
                elif p!=hpos:
                    ret.append(f'1 {p} {hpos}')
            elif p!=hpos:
                ret.append(f'1 {p} {hpos}')
            nc-=1
        elif v and p!=hpos:
            ret.append(f'1 {p} {hpos}')
        else:
            if zc==1:
                if pzc==n or (pzc==n-1 and x[-1][1]<0):
                    break
                else: ret.append(f'2 {p}')
            else:
                ret.append(f'1 {p} {x[0][0]}')
            zc-=1
    print("\n".join(ret))
solve()

# 200000
# print('\n'.join([ f'{x[0]} {x[1]} {x[2]}' if x[0]==1 else f'{x[0]} {x[1]} {x[2]}'  for x in ret]))

# wrong output format Unexpected end of file - int32 expected

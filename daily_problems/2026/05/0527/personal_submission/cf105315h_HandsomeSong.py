import sys
import heapq
input=sys.stdin.buffer.readline
def II():
    return int(input())
def MII():
    return map(int,input().split())
t=II()
outs=[]
for _ in range(t):
    n,k=MII()
    items=[]
    for _ in range(n):
        a,b=MII()
        items.append((b,a))
    items.sort()
    heap=[]
    sm=0
    mxv=-10**18
    need=k-1
    for b,a in items:
        if len(heap)==need:
            v=sm+ a-b
            if v>mxv:
                mxv=v
        if k>1:
            if len(heap)<need:
                heapq.heappush(heap,a)
                sm+=a
            elif a>heap[0]:
                sm+=a-heapq.heapreplace(heap,a)
    outs.append(str(mxv))
print('\n'.join(outs))
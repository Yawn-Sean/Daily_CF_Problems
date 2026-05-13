import sys
import heapq
import bisect
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
n,m,k=MII()
j=LII()
j.sort()
diff=[0]*(k+2)
heap=[]
for _ in range(m):
    l,r,x=MII()
    if l>1:
        diff[l-1]+=x
        heapq.heappush(heap,(-diff[l-1],l-1))
    if r<k:
        diff[r]-=x
        heapq.heappush(heap,(-diff[r],r))
    H_req=0
    while heap:
        neg_val,i=heap[0]
        val=-neg_val
        if diff[i]==val:
            H_req=max(0,val)
            break
        else:
            heapq.heappop(heap)
    print(n-bisect.bisect_left(j,H_req))
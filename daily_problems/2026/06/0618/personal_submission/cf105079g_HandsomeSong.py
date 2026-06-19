import sys
import heapq
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
n=II()
a=LII()
b=LII()
offset=0
heap=[-aa for aa in a]
heapq.heapify(heap)
for i in range(n):
    offset+=b[i]
    mx=-heapq.heappop(heap)
    actual=mx+offset
    new=(actual-actual//2)-offset
    heapq.heappush(heap,-new)
print(sum(-aa for aa in heap)+offset*n)
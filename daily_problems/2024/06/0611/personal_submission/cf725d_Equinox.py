import sys
from heapq import *


sys.stdin = open('in.txt', 'r')

N = int(input())

curx, curw = map(int, input().split())

tw = [list(map(int, input().split())) for _ in range(N - 1)]

tw.sort(key=lambda x: x[0])

p = N - 2
pq = []

while ~p and tw[p][0] > curx:
    heappush(pq, tw[p][1] - tw[p][0] + 1)
    p -= 1

res = len(pq) + 1
while pq and curx >= pq[0]:
    curx -= heappop(pq)
    while ~p and tw[p][0] > curx:
        heappush(pq, tw[p][1] - tw[p][0] + 1)
        p -= 1
    res = min(res, len(pq) + 1)

print(res)
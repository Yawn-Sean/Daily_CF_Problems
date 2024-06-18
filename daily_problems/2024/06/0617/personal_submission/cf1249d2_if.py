import heapq
import math, itertools
import sys, collections
import bisect, queue
import copy
input = lambda: sys.stdin.readline().rstrip()

n,m = map(int,input().split())
list1 = [[] for i in range(int(2e5)+10)]
for i in range(n):
    a,b = map(int,input().split())
    list1[a].append([-b,i+1])
tt = []
heapq.heapify(tt)
fu = [0 for i in range(int(2e5)+10)]
temp = 0
res = []
for i in range(1,int(2e5)+10):
    for p in list1[i]:
        heapq.heappush(tt,p)
        fu[-p[0]] += 1
    while len(tt) - temp > m:
        t = heapq.heappop(tt)
        fu[-t[0]] -= 1
        res.append(t[1])
    temp += fu[i]
print(len(res))
print(*res)

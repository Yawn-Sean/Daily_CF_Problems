import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
from heapq import heapify, heapreplace

def solve():
    # key: 類似反悔貪心思路
    # 如何解決多個vis問題?
    # 使用堆+集合方便及時修改
    
    vis = set(a)
    q = [-x for x in a]
    heapify(q)
    
    while True:
        x = -q[0] # heappop，找可能值
        new_val = x >> 1
        while new_val in vis:
            new_val >>= 1
        if new_val == 0: # 找不到更小了
            break
        
        vis.remove(x)
        vis.add(new_val)
        heapreplace(q, -new_val) # 比pop+push快
    
    print(*[-x for x in q])

               
for _ in range(1):
    n = int(input())
    a = list(MII())
    solve()
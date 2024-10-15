import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
from collections import deque

def solve():
    # key: 兩次bfs技巧(不用重複初始化)
    # 處理森林的技巧，遍歷頂點
    # 如果邊權為1，可利用deque性質，最後遍歷到的點距離最大
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v = MII()
        g[u - 1].append(v - 1)
        g[v - 1].append(u - 1)
    
    dist = [-n] * n
    last = [-1] * n
    diameters = []
    for i in range(n): # 因為是森林，要多次探訪
        if dist[i] != -n: 
            continue
        
        dist[i] = -1
        q = deque([i])
        while q:
            x = q.popleft()
            for y in g[x]:
                if dist[y] == -n:
                    dist[y] = dist[x] - 1
                    q.append(y)
        
        dist[x] = 0
        q = deque([x])
        while q:
            x = q.popleft()
            for y in g[x]:
                if dist[y] < 0:
                    dist[y] = dist[x] + 1
                    last[y] = x
                    q.append(y)
        
        dis = dist[x]
        for _ in range(dis // 2):
            x = last[x]
        diameters.append((dis, x))
    
    diameters.sort(reverse=True)
    
    outs = []
    cur = mx = -1
    for dis, x in diameters:
        if cur == -1:
            cur, mx = x, dis
        else: # 因為diameter從大到小，只需比兩個(其實可略過dis)
            outs.append((x + 1, cur + 1))
            mx = max(mx, dis, (mx + 1) // 2 + (dis + 1) // 2 + 1)
    print(mx)
    for out in outs:
        print(*out)
             
                
for _ in range(1):
    n, m = MII()
    solve()
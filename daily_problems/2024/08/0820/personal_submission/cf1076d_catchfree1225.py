import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
from heapq import heappush, heappop
from collections import deque
inf = int(1e15)

def solve():
    us, vs, ws = [[-1] * m for _ in range(3)] # 節省一半空間
    g = [[] for _ in range(n)]
    for ei in range(m):
        u, v, w = MII()
        u -= 1
        v -= 1
        us[ei], vs[ei], ws[ei] = u, v, w
        g[u].append(ei)
        g[v].append(ei)

    dist = [0] + [inf] * (n - 1)
    last = [-1] * n
    q = [(0, 0)]
    while q:
        wf, x = heappop(q)
        if wf > dist[x]:
            continue
        for ei in g[x]:
            y = x ^ us[ei] ^ vs[ei]
            new_d = wf + ws[ei]
            if dist[y] > new_d:
                dist[y] = new_d
                last[y] = ei
                heappush(q, (new_d, y))
   
    cnt = min(k, n - 1) # 至多k個，可能不到k個(最短路徑樹:n-1)
    # ans = []
    # vis = [True] + [False] * (n - 1)
    # q = deque([0])
    # while q:
    #     if len(ans) == cnt:
    #         break
    #     x = q.popleft()
    #     for ei in g[x]:
    #         y = x ^ us[ei] ^ vs[ei]
    #         if not vis[y] and dist[y] - dist[x] == ws[ei]:
    #             vis[y] = True
    #             ans.append(ei + 1)
    #             if len(ans) == cnt:
    #                 break
    #             q.append(y)
    # print(len(ans))
    # print(*ans)
    
    st_range = sorted(range(1, n), key=lambda x: dist[x]) # 邊權為正，前cnt個大小就會剛好是樹
    ans = [last[x] + 1 for x in st_range[:cnt]]
    print(len(ans))
    print(*ans)
    
for _ in range(1):
    n, m, k = MII()
    solve()
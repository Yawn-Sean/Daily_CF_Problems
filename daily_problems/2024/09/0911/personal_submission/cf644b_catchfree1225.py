import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
from collections import deque

def solve():
    # Key: 直接紀錄執行時刻!
    # 類DP->q中存的是預計跑完之後的時間
    # 移除: 時間<=ti, 增加: q[-1]+di
    
    ans = [-1] * n
    q = deque()
    for i in range(n):
        ti, di = MII()
        while q and q[0] <= ti:
            q.popleft()
        if len(q) <= b:
            if not q:
                ans[i] = ti + di
            else:
                ans[i] = q[-1] + di
            q.append(ans[i])
    print(*ans)
        
               
for _ in range(1):
    n, b = MII()
    solve()
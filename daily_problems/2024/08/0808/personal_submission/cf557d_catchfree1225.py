import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
from math import comb

def solve():
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v = GMI()
        g[u].append(v)
        g[v].append(u)
        
    # key: G為雙分圖 ⇔ G沒有奇數長度cycle
    # 檢查雙分圖: 2-colorable
    # 從特例想起，討論三個點的情形
    # 加3邊: 原本沒點，c(n,3)
    if m == 0:
        print(3, comb(n, 3))
        return
    
    # 對每個節點做dfs，會得到連通的雙分圖
    # 加2邊: 鏈長(連通塊)<=2
    # 加1邊: 鏈長(連通塊)>2
    # 加0邊: 非雙分圖，原本就有奇數長度cycle
    ans1 = 0
    vis = [-1] * n
    for i in range(n):
        if vis[i] != -1:
            continue
        vis[i] = 0
        c0, c1 = 1, 0
        st = [i]
        while st:
            x = st.pop()
            for y in g[x]:
                if vis[y] != -1:
                    if vis[x] == vis[y]: # 非雙分圖
                        print(0, 1)
                        return
                else:
                    vis[y] = vis[x] ^ 1
                    if vis[y]: c1 += 1
                    else: c0 += 1
                    st.append(y)
        ans1 += comb(c0, 2) + comb(c1, 2)
    
    if ans1:
        print(1, ans1) # 連通雙分圖(連通塊>2)
    else:
        print(2, m * (n - 2)) # 選一個邊+其餘點(連通塊<=2)
        
               
for _ in range(1):
    n, m = MII()
    solve()
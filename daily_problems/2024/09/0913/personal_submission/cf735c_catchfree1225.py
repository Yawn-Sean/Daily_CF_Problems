import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

def solve():
    # Key: AVLTree變形，選手都先放在葉子節點
    # 單淘汰: 最多n-1次比賽(邊)
    # 平衡: 比賽時離葉子距離不能超過1
    # (兩棵子樹的最大高度差為1)
    # f[h+1] = f[h] + f[h-1]; f[i]: 高度為i之最少節點數
    # !注意: 湊出的新樹f[h+1]，不能超過n!
    # (答案為較大的子樹)
    
    if n < 2: # 無法比較
        print(0)
        return
        
    t1, t2 = 2, 1 # Base_case, 至少需要1個邊
    cur = 0
    while t1 <= n:
        t1, t2 = t1 + t2, t1 
        cur += 1
    print(cur)       
        
for _ in range(1):
    n = int(input())
    solve()
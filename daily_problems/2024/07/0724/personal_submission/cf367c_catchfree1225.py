import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

def solve():
    # G有EC ⇔ G為連通圖且∀v, deg(v)為偶數
    # G有ET ⇔ 僅有<=2個deg為奇數(S, T)，其他deg都是偶數 
    def calc(k: int):
        d = k - 1
        if d & 1 == 0:
            tot_deg = k * d
        else: # 至多兩個點為奇數，其他都是偶數
            tot_deg = k * d + max(k - 2, 0)
        return tot_deg // 2 + 1 
    
    ans = 0
    for i in range(1, m + 1): # 枚舉節點數
        if calc(i) > n:
            break
        ans += a[i - 1]
    print(ans)
               
               
for _ in range(1):
    n, m = MII()
    a = sorted([tuple(MII())[1] for _ in range(m)], reverse=True)
    solve()
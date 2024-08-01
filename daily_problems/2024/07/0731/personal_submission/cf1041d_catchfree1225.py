import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

def solve():
    ls, rs = [], []
    for _ in range(n):
        l, r = MII()
        ls.append(l)
        rs.append(r)
    
    ans = r = 0 # 類單調隊列，因為飛行距離累計是線性的，可以只考慮間隔數
    sum_ascend = sum_gap = 0 # 累積飛行段與中間間隔段，間隔大小嚴格小於h
    for l in range(n):
        while r < n - 1 and sum_gap + ls[r + 1] - rs[r] < h:
            sum_ascend += rs[r] - ls[r] # O(1)避免計算前綴和
            sum_gap += ls[r + 1] - rs[r]
            r += 1
        ans = max(ans, sum_ascend + h + rs[r] - ls[r])
        if l < n - 1:
            sum_ascend -= rs[l] - ls[l]
            sum_gap -= ls[l + 1] - rs[l]
    print(ans)
                
for _ in range(1):
    n, h = MII()
    solve()
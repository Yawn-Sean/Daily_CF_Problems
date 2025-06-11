import sys
input = lambda: sys.stdin.readline().strip()

def solve():
    def query(x1, y1, x2, y2):
        print('?', x1, y1, x2, y2, flush=True)
        return int(input())
          
    def findRectangle(x1, y1, x2, y2):
        # 取得c2, r2: 從左上拉(從左往右數第一個等於1的點)
        l, r = x1, x2
        while l < r:
            mid = (l + r) >> 1
            if query(x1, y1, mid, y2) > 0:
                r = mid
            else:
                l = mid + 1
        r2 = l
        
        l, r = y1, y2
        while l < r:
            mid = (l + r) >> 1
            if query(x1, y1, x2, mid) > 0:
                r = mid
            else:
                l = mid + 1
        c2 = l
        
        # 取得c1, r1: 從右下拉(從右往左數第一個等於1的點)
        l, r = x1, r2 # 注意二分要取從左往右最後一個
        while l < r:
            mid = (l + r + 1) >> 1
            if query(mid, y1, x2, c2) > 0:
                l = mid
            else:
                r = mid - 1
        r1 = l
        
        l, r = y1, c2
        while l < r:
            mid = (l + r + 1) >> 1
            if query(x1, mid, r2, y2) > 0:
                l = mid
            else:
                r = mid - 1
        c1 = l
        
        return [r1, c1, r2, c2]
    
    
    l, r = 1, n
    while l < r:
        mid = (l + r) >> 1
        if query(1, 1, mid, n):
            r = mid
        else:
            l = mid + 1
            
    if l < n and query(l + 1, 1, n, n): # 上下分割(l可能超過n)
        rec1 = findRectangle(1, 1, l, n)
        rec2 = findRectangle(l + 1, 1, n, n)
    else: # 左右分割
        l, r = 1, n
        while l < r:
            mid = (l + r) >> 1
            if query(1, 1, n, mid):
                r = mid
            else:
                l = mid + 1
        rec1 = findRectangle(1, 1, n, l)
        rec2 = findRectangle(1, l + 1, n, n)
    print('!', *rec1, *rec2)
        
     
for _ in range(1):
    n = int(input())
    solve()
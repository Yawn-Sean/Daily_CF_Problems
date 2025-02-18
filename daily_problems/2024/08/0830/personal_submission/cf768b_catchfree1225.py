import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
from functools import cache

def solve():
    # key: 切割區間問題，先畫圖轉換長度為下標!
    # 分而治之: 沒必要計算不同點之對應下標，切割成相同子問題，在子問題上的下標做計算
    # left_interval = [0,ln-1]
    # mid_point = ln
    # right_interval = [ln+1,ln*2]
    
    @cache
    def dfs(n, l, r) -> int:
        if n <= 1:
            return n
        p, q = divmod(n, 2)
        ln = (1 << p.bit_length()) - 1 # 打表得知長度
        
        if 0 <= l and r <= ln - 1:
            return dfs(p, l, r)
        if ln + 1 <= l and r <= ln * 2:
            return dfs(p, l - (ln + 1), r - (ln + 1))
        
        ans = 0
        if l <= ln - 1: ans += dfs(p, l, min(ln - 1, r))
        if l <= ln <= r: ans += q
        if r >= ln + 1: ans += dfs(p, max(l - (ln + 1), 0), r - (ln + 1))
        return ans

    print(dfs(n, l ,r))
               
for _ in range(1):
    n, l, r = MII()
    l -= 1
    r -= 1
    solve()
import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

def solve():
    # 雙重sigma, 等於計算所有子數組情況
    # 統計次數，會發現類似正態分布的結構
    # 記數次數從外往內遞減
    # 把數字小的放在外側，字典序較大
    # 兩種case: 放前面，放後面 => 放完再排列剩餘元素
    # 剩餘數字有前後兩種選擇，2**sz種可能排列
    
    k = m - 1 # 避免特判剛好，我們改取上一位字典序
    ans = [0] * n
    l, r = 0, n - 1
    for i in range(1, n):
        sz = n - 1 - i
        # if 2 ** sz <= k: k -= 2 ** sz
        # 小技巧: 直接看k二進制
        if k >> sz & 1:   
            ans[r] = i
            r -= 1
        else:
            ans[l] = i
            l += 1
    ans[l] = n # l, r會相同
    print(*ans)
               
for _ in range(1):
    n, m = MII()
    solve()
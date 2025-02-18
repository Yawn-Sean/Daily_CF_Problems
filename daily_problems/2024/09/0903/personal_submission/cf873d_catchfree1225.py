import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

def solve():
    # key: 考慮貢獻量->最少變化=2
    # a[l:r]非有序，但a[l:m], a[m:r]為有序
    # 可以透過交換左邊最大與右邊最小做到!
    # 總結: k一定是奇數(完全有序也會跑1次)，改變(k-1)//2次
    # (如果換不完或k是偶數return-1)
    
    a = list(range(1, n + 1))
    def merge(l, r):
        nonlocal cnt
        if cnt == 0 or l + 1 == r:
            return
        m = (l + r) >> 1
        a[m - 1], a[m] = a[m], a[m - 1]
        cnt -= 1
        merge(l, m)
        merge(m, r)
    
    if k & 1 == 0:
        print(-1)
        return
    cnt = k // 2
    merge(0, n)    
    print(' '.join(map(str, a)) if cnt == 0 else -1)
    
               
for _ in range(1):
    n, k = MII()
    solve()
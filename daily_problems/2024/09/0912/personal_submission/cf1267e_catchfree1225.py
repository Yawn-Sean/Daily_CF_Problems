import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
    
def solve():
    lst = list(range(m))
    def calc(ci):
        lst.sort(key=lambda x: a[x][ci] - a[x][-1])
        pre = [0] * (m + 1)
        pre_bad = [0] * (m + 1)
        for i, li in enumerate(lst):
            pre[i + 1] = pre[i] + a[li][ci]
            pre_bad[i + 1] = pre_bad[i] + a[li][-1]
    
        l, r = 0, m
        while l < r:
            mid = (l + r) >> 1
            if pre[-1] - pre[mid] >= pre_bad[-1] - pre_bad[mid]:
                r = mid
            else:
                l = mid + 1
        return lst[:l]

    ans = list(range(m))
    for ci in range(n - 1):
        val = calc(ci)
        if len(val) < len(ans):
            ans = val
    print(len(ans))
    print(*[x + 1 for x in ans])    
               
for _ in range(1):
    n, m = MII()
    a = [tuple(MII()) for _ in range(m)]
    solve()
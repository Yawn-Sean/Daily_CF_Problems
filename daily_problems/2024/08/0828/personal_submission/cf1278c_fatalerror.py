import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())

def solve():
    n = ii()
    arr = [x*2-3 for x in mii()]
    s = sum(arr)
    if s == 0:
        return 0
    ans = n*2
    mp = {0: -1}
    pres = 0
    for i, x in enumerate(arr):
        pres += x
        if i < n:
            mp[pres] = i
        if i >= n-1:
            if pres-s in mp:
                ans = min(ans, i-mp[pres-s])
    return ans

for _ in range(ii()):
    print(solve())
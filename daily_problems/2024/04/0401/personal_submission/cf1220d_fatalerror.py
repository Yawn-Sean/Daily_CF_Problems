import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

from collections import defaultdict

def solve():
    n = ii()
    arr = lii()
    mp = defaultdict(list)
    for x in arr:
        mp[x&-x].append(x)
    mx = max(mp.keys(), key=lambda lb: len(mp[lb]))
    ans = []
    for lb, vals in mp.items():
        if lb != mx:
            ans.extend(vals)
    return ans

ans = solve()
print(len(ans))
print(*ans)
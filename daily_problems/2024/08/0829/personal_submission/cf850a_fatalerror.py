import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lii = lambda: list(mii())

def solve():
    n = ii()
    if n > 11:
        return []
    pts = [lii() for _ in range(n)]
    return [i+1 for i in range(n) if all(sum((x-y)*(x-z) for x, y, z in zip(pts[i], pts[j], pts[k])) <= 0 for j in range(n) for k in range(j))]

ans = solve()
print(len(ans))
print(*ans)
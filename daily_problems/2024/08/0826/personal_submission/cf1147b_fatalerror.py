import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lii = lambda: list(mii())

def solve():
    n, m = mii()
    edges = []
    vis = set()
    for _ in range(m):
        u, v = mii()
        u -= 1; v -= 1
        if u > v:
            u, v = v, u
        edges.append((u, v))
        vis.add(u * n + v)

    cur = n
    for p in range(2, n+1):
        if cur % p:
            continue
        while cur % p == 0:
            cur //= p
        offset = n // p
        valid = True
        for u, v in edges:
            u2 = (u + offset) % n
            v2 = (v + offset) % n
            x = u2 * n + v2 if u2 <= v2 else v2 * n + u2
            if x not in vis:
                valid = False
                break
        if valid:
            return True
    return False

print('Yes' if solve() else 'No')
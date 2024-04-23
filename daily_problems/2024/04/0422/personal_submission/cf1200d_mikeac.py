import sys

# region fastio
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))
# endregion fastio

# MOD = 998_244_353
# MOD = 10 ** 9 + 7
# DIR4 = ((-1, 0), (0, 1), (1, 0), (0, -1)) #URDL
# DIR8 = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))


def solve() -> None:
    n, k = mint()
    g = []
    for _ in range(n):
        g.append(input())
    
    ans = 0
    d = [[0] * (n + 1) for _ in range(n + 1)]
    for i in range(n):
        mn, mx = n, -1
        for j in range(n):
            if g[i][j] == 'B':
                mn = min(mn, j)
                mx = max(mx, j)
        if mn > mx:
            ans += 1
        elif mx - mn + 1 <= k:
            x1, y1 = max(0, i - k + 1), max(0, mx - k + 1)
            x2, y2 = i, mn
            d[x1][y1] += 1
            d[x1][y2 + 1] -= 1
            d[x2 + 1][y1] -= 1
            d[x2 + 1][y2 + 1] += 1
    
    for j in range(n):
        mn, mx = n, -1
        for i in range(n):
            if g[i][j] == 'B':
                mn = min(mn, i)
                mx = max(mx, i)
        if mn > mx:
            ans += 1
        elif mx - mn + 1 <= k:
            x1, y1 = max(0, mx - k + 1), max(0, j - k + 1)
            x2, y2 = mn, j
            d[x1][y1] += 1
            d[x1][y2 + 1] -= 1
            d[x2 + 1][y1] -= 1
            d[x2 + 1][y2 + 1] += 1

    more = 0
    for i in range(n):
        for j in range(n):
            if i:
                d[i][j] += d[i - 1][j]
            if j:
                d[i][j] += d[i][j - 1]
            if i and j:
                d[i][j] -= d[i - 1][j - 1]
            more = max(more, d[i][j])

    print(ans + more)

solve()

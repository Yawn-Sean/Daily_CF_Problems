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
    n, m = mint()
    g = []
    for _ in range(n):
        g.append(ints())
    
    row = [0] * n
    col = [0] * m
    for i, r in enumerate(g):
        for j, x in enumerate(r):
            row[i] += x
            col[j] += x
    ro, co = [0] * n, [0] * m
    while min(row) < 0 or min(col) < 0:
        for i in range(n):
            if row[i] < 0:
                row[i] = -row[i]
                ro[i] ^= 1
                for j in range(m):
                    col[j] -= g[i][j] * 2
                    g[i][j] = -g[i][j]
        for j in range(m):
            if col[j] < 0:
                col[j] = -col[j]
                co[j] ^= 1
                for i in range(n):
                    row[i] -= g[i][j] * 2
                    g[i][j] = -g[i][j]
    
    print(sum(ro), *(i + 1 for i, v in enumerate(ro) if v))
    print(sum(co), *(i + 1 for i, v in enumerate(co) if v))


solve()

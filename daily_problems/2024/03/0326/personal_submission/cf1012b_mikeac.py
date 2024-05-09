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
    n, m, q = mint()

    fa = list(range(n + m))

    def find(x: int):
        cur = x
        while x != fa[x]:
            x = fa[x]
        while fa[cur] != x:
            fa[cur], cur = x, fa[cur]
        return x

    def union(x: int, y: int) -> bool:
        fx, fy = find(x), find(y)
        if fx == fy:
            return False
        fa[fx] = find(fy)
        return True

    ans = n + m - 1
    for _ in range(q):
        x, y = mint()
        ans -= union(x - 1, y + n - 1)
    print(ans)

solve()

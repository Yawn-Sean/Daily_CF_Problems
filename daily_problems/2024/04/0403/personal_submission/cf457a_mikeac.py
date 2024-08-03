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
    s1 = list(map(int, list(input())))
    s2 = list(map(int, list(input())))

    n = max(len(s1), len(s2))

    if n == 1:
        print(">" if s1[0] > s2[0] else "=" if s1[0] == s2[0] else "<")
        return

    if len(s1) < n: s1 = [0] * (n - len(s1)) + s1
    if len(s2) < n: s2 = [0] * (n - len(s2)) + s2

    x = y = 0

    for i in range(n - 2):
        x, y = x + y + s1[i] - s2[i], x + s1[i] - s2[i]

    x += s1[-2] - s2[-2]
    y += s1[-1] - s2[-1]

    if x == 0:
        print(">" if y > 0 else "=" if y == 0 else "<")
    elif x * y > 0:
        print(">" if x > 0 else "<")
    else:
        l = 5 * x * x
        r = (- 2 * y - x) * (- 2 * y - x)
        if x < 0: l, r = r, l
        print(">" if l > r else "=" if l == r else "<")

solve()

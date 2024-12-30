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
    n = sint()
    s = input()
    ans = len(s) + 1
    cnt_r = cnt_d = 0
    can_r = can_d = 0
    for c in s:
        if c == "R":
            cnt_r += 1
            if can_r == 0:
                can_r = n - cnt_d
        else:
            cnt_d += 1
            if can_d == 0:
                can_d = n - cnt_r
    ans += can_r * (n - 1 - cnt_r) + can_d * (n - 1 - cnt_d) - (n - 1 - cnt_r) * (n - 1 - cnt_d)
    print(ans)

for _ in range(int(input())):
    solve()

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
    nums = ints()
    cnt = [0] * 101
    ans = [0] * n
    s = 0
    for i, x in enumerate(nums):
        cnt[x] += 1
        s += x
        if s <= m:
            continue
        tmp = s
        j = 100
        while tmp > m:
            v = min(cnt[j] - (j == x), (tmp - m + j - 1) // j)
            ans[i] += v
            tmp -= v * j
            j -= 1
    print(*ans)

solve()

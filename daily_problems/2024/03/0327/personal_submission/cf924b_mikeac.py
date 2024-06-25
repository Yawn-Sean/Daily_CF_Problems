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
    n, u = mint()
    nums = ints()
    p, q = -1, 1
    r = 0
    for l in range(1, n - 1):
        r = max(r, l)
        while r < n - 1 and nums[r + 1] - nums[l - 1] <= u:
            r += 1
        if l < r and (nums[r] - nums[l]) * q > p * (nums[r] - nums[l - 1]):
            p, q = nums[r] - nums[l], nums[r] - nums[l - 1]
    print(p / q)

solve()

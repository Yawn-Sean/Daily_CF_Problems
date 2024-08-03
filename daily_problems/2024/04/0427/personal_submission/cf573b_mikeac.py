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
    nums = ints()
    nums[0] = nums[-1] = 1
    for i in range(1, n):
        nums[i] = min(nums[i], nums[i - 1] + 1)
    for i in range(n - 2, -1, -1):
        nums[i] = min(nums[i], nums[i + 1] + 1)
    print(max(nums))

solve()

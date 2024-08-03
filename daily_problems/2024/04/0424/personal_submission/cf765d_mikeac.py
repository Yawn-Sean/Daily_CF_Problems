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
    pos = set(nums)
    for x in pos:
        if nums[x - 1] != x:
            print(-1)
            return
        
    g = [0] * n
    h = list(pos)
    x2i = {v:i for i, v in enumerate(h, 1)}
    for i, x in enumerate(nums):
        g[i] = x2i[x]
    print(len(h))
    print(*g)
    print(*h)


solve()

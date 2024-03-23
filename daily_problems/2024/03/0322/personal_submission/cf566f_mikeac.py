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
    nums.sort()
    mx = nums[-1]
    cnt = [0] * (mx + 1)
    for x in nums:
        cnt[x] += 1
    for x in nums:
        for y in range(x * 2, mx + 1, x):
            if cnt[y] == 0:
                continue
            cnt[y] = max(cnt[y], cnt[x] + 1)
    print(max(cnt))

solve()

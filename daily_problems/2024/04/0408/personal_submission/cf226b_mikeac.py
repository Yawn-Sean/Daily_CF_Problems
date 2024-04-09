import sys
from itertools import accumulate

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
    nums.sort(reverse=True)
    pres = list(accumulate(nums, initial=0))

    res1 = 0
    for i in range(1, n):
        res1 += i * nums[i]

    q = sint()
    qry = ints()
    ans = [0] * q
    for i, k in enumerate(qry):
        if k == 1:
            ans[i] = res1
        else:
            l = t = 1
            while l < n:
                r = min(n, l + pow(k, t))
                ans[i] += (pres[r] - pres[l]) * t
                l = r
                t += 1
    print(*ans)

solve()

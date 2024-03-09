import math
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
    nums = []
    for _ in range(n):
        nums.append(tuple(mint()))
    
    s = set()
    for x in nums[0]:
        d = 2
        while d * d <= x:
            if x % d == 0:
                s.add(d)
                while x % d == 0:
                    x //= d
            if x == 1:
                break
            d += 1
        if x > 1: s.add(x)
    
    for p in s:
        check = True
        for i in range(n):
            if not (nums[i][0] % p == 0 or nums[i][1] % p == 0):
                check = False
                break
        if check:
            print(p)
            return
    print(-1)

solve()

import sys
from heapq import *

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
    n, k, x = mint()
    nums = ints()
    neg = zero = 0
    h = []
    for i, a in enumerate(nums):
        if a < 0:
            neg += 1
        elif a == 0:
            zero += 0
        h.append((abs(a), i))
    
    if k < zero:
        print(*nums)
        return

    heapify(h)
    if not neg & 1:
        a, i = heappop(h)
        m = a // x + 1
        if k < m:
            if nums[i] > 0:
                nums[i] -= k * x
            else:
                nums[i] += k * x
            print(*nums)
            return
        
        if nums[i] >= 0:
            nums[i] -= m * x
        else:
            nums[i] += m * x
        k -= m
        heappush(h, (abs(nums[i]), i))
    while k:
        a, i = heappop(h)
        if nums[i] >= 0:
            nums[i] += x
        else:
            nums[i] -= x
        k -= 1
        heappush(h, (abs(nums[i]), i))
    print(*nums)

solve()

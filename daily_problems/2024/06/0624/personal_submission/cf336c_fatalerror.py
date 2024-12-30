import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())

from functools import reduce

n = ii()
nums = list(mii())
for b in range(nums[-1].bit_length() - 1, -1, -1):
    subs = [x for x in nums if x >> b & 1]
    if subs:
        ands = reduce(int.__and__, subs, -1)
        if not ands & ((1 << b) - 1):
            print(len(subs))
            print(*subs)
            break
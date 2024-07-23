import sys
from sortedcontainers import SortedList
from itertools import accumulate
from collections import Counter
from bisect import bisect_left
from bisect import bisect_right
from string import ascii_uppercase
from math import inf

input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
LMI = lambda: list(map(int, input().split()))
LI = lambda: list(input())
II = lambda: int(input())
fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y
P = 1_000_000_007

sys.stdin = open('in.txt', 'r')
def solve():
    n = II()
    s = LMI()

    s.sort()

    segs: list[int] = sorted(s[i + 1] - s[i] for i in range(n - 1)) + [10**18 + 1]

    acc = list(accumulate(segs, initial=0))

    q = II()
    ans = []
    for _ in range(q):
        l, r = MII()
        x = r - l + 1
        bound = bisect_right(segs, x)
        ans.append(acc[bound] + (n - bound) * x)

    print(' '.join([str(x) for x in ans]))
    pass

if __name__ == "__main__":
    T = 1
    # T = II()
    for _ in range(T):
        solve()
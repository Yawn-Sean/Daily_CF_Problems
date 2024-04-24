"""
双指针。将数组升序排序后，需要将某个前缀增大到`mn`，同时将某个后缀增大到`upper`，并且前缀和后缀不能相交。枚举后缀长度、计算对应前缀的`mn`更加方便。在后缀长度增加的同时，前缀长度一定不增，所以可以用同向双指针解决。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

from itertools import accumulate

def solve():
    n, upper, cfull, cmn, money = lii()
    origin = lii()
    order = sorted(range(n), key=origin.__getitem__)
    arr = [origin[idx] for idx in order]
    pres = list(accumulate(arr, initial=0))

    # arr[0:inc+1]需要增大至mn
    # arr[full:n]需要增大至upper
    inc = 0
    ans = 0
    record = (-1, 0, n)  # (inc, mn, full)
    # 保持full=n，向右移动inc
    while inc < n and arr[inc] * (inc+1) - pres[inc+1] <= money:
        # arr[0:inc+1]先增大至arr[inc]，再继续增加且不超过upper
        mn = min(arr[inc] + (money - arr[inc] * (inc+1) + pres[inc+1]) // (inc+1), upper)
        ans = cmn * mn
        record = (inc, mn, n)
        inc += 1

    # 向左移动full和inc
    for full in range(n-1, -1, -1):
        money -= upper - arr[full]
        if money < 0:
            break
        while inc >= 0 and (inc >= full or arr[inc] * (inc+1) - pres[inc+1] > money):
            inc -= 1
        mn = min(arr[inc] + (money - arr[inc] * (inc+1) + pres[inc+1]) // (inc+1), upper) if inc >= 0 else upper
        tmp = cmn*mn + cfull*(n-full)
        if tmp > ans:
            ans = tmp
            record = (inc, mn, full)

    inc, mn, full = record
    for i in range(inc+1):
        idx = order[i]
        origin[idx] = mn
    for i in range(full, n):
        idx = order[i]
        origin[idx] = upper

    print(ans)
    print(*origin)

solve()

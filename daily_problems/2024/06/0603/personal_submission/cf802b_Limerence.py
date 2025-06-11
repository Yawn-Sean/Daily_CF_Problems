# ----------------------------------------------
# Author: zhengyi20thu
# Time: 2024-06-03 14:02:17
# ----------------------------------------------

import sys

input = sys.stdin.readline


def inp():
    return int(input())


def inlt():
    return list(map(int, input().split()))


def insr():
    s = input()
    return list(s[: len(s) - 1])


def invr():
    return map(int, input().split())


def ins():
    return input().strip()


from collections import defaultdict
from heapq import heapify, heappop, heappush

INF = 0x3F3F3F3F


def solve():
    n, k = invr()
    a = inlt()
    idx = defaultdict(list)
    ptr = defaultdict(int)
    for i, x in enumerate(a):
        idx[x].append(i)
        ptr[x] = 1
    cost = 0
    cur_set = set()
    hpq = []
    for x in a:
        if x in cur_set:
            # heappop(hpq)
            if ptr[x] < len(idx[x]):
                heappush(hpq, (-idx[x][ptr[x]], x))
                ptr[x] += 1
            else:
                heappush(hpq, (-INF, x))
            continue
        if len(cur_set) < k:
            cur_set.add(x)
            if ptr[x] < len(idx[x]):
                heappush(hpq, (-idx[x][ptr[x]], x))
                ptr[x] += 1
            else:
                heappush(hpq, (-INF, x))
            cost += 1
        else:
            to_del = heappop(hpq)[1]
            cur_set.remove(to_del)
            cur_set.add(x)
            if ptr[x] < len(idx[x]):
                heappush(hpq, (-idx[x][ptr[x]], x))
                ptr[x] += 1
            else:
                heappush(hpq, (-INF, x))
            cost += 1
    return cost


t = 1
while t:
    t -= 1
    print(solve())

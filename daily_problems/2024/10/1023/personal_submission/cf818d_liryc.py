'''
https://codeforces.com/problemset/submission/818/287546224
818D
2024/10/23 Y1
1700
Priority Queue
'''

from heapq import heappop, heappush
import sys
from collections import Counter
input = lambda: sys.stdin.readline().strip()

def init():
    n, ca = map(int, input().split())
    a = list(map(int, input().split()))
    return n, ca, a

def solve(n: int, ca: int, a: list[int]):
    na = 0
    hp = []
    cnt = Counter()
    for x in a:
        if x == ca:
            na += 1
            while hp and (hp[0][0] < na or hp[0][0] < cnt[hp[0][1]]):
                c, k = heappop(hp)
                if c == cnt[k]:
                    cnt.pop(k)
        else:
            if not x in cnt and na > 0:
                pass
            else:
                cnt[x] += 1
                heappush(hp, (cnt[x], x))
    while hp and hp[0][0] < cnt[hp[0][1]]:
        heappop(hp)
    return -1 if not hp else hp[0][1]

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)

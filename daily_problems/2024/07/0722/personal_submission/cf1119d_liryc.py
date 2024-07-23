'''
https://codeforces.com/contest/1119/submission/271861312
CF1119D
2024/7/22 Y1
1800
prefix sum + binary search
'''

from bisect import bisect_right
from itertools import accumulate, pairwise

if __name__ == '__main__':
    n = int(input())
    a = []
    for x, y in pairwise(sorted(map(int, input().split()))):
        if y > x:
            a.append(y - x)
    a.sort()
    ps = list(accumulate(a))
    m = int(input())
    ans = []
    for _ in range(m):
        l, r = map(int, input().split())
        d = r - l + 1
        x = 0
        i = bisect_right(a, d)
        if i:
            x = ps[i - 1]
        x += (len(a) - i + 1) * d
        ans.append(x)
    print(*ans)


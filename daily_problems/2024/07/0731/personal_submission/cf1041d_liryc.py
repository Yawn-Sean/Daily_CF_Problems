'''
https://codeforces.com/contest/1041/submission/273666829
1041D
20240731 Y1
1700
two pointers
'''

from itertools import pairwise

if __name__ == '__main__':
    n, h = map(int, input().split())
    a = []
    for _ in range(n):
        x1, x2 = map(int, input().split())
        a.append((x1, x2))
    # a.sort() # input already ascending
    a.append((a[-1][-1] + h, a[-1][-1] + h))
    i, maxd = 0, h + a[0][1] - a[0][0]
    l, r = a[0][0] - h + 1, a[0][1] + 1
    for (x1, x2), (y1, y2) in pairwise(a):
        d = y1 - x2
        while d:
            e = a[i][0] - l
            if e >= d:
                l += d
                r = y2 + 1
                maxd = max(maxd, r - l)
                break
            else:
                r += e
                d -= e
                l = a[i][1]
                i += 1
    print(maxd)




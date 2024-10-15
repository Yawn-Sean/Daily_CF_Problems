'''
https://codeforces.com/contest/593/submission/280092415
593B
2024/9/6 Y1
1600
sorting, geometry
所有直线按与x=x1的交点排序，然后再与x=x2的交点排序，只有两个排序顺序完全一样的时候才是没交点的，否则必有交点
特殊1：直线与y轴平行，在本题中不存在
特殊2：直线在边界处相交，所以要把另一边界作为第二排序key
'''

import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n = int(input())
    x1, x2 = map(int, input().split())
    a = []
    for _ in range(n):
        k, b = map(int, input().split())
        a.append((k, b))
    return n, a, x1, x2

def solve(n, a, x1, x2):
    y1 = [k * x1 + b for k, b in a]
    y2 = [k * x2 + b for k, b in a]
    sa1 = list(sorted(range(n), key = lambda i: (y1[i], y2[i])))
    sa2 = list(sorted(range(n), key = lambda i: (y2[i], y1[i])))
    return not sa1[:] == sa2[:]

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    if ans:
        print("Yes")
    else:
        print("No")

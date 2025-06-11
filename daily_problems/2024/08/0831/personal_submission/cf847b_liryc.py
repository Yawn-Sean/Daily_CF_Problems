'''
https://codeforces.com/contest/847/submission/278875833
847B
2024/8/31 Y1
1600
sorting
'''

from bisect import bisect_left
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n = int(input())
    a = list(map(int, input().split()))
    return n, a

def solve(n: int, a: list[int]):
    sa = []
    for x in a:
        i = bisect_left(sa, 1, key = lambda l: l[-1] <= x)
        if i >= len(sa):
            sa.append([x])
        else:
            sa[i].append(x)
    return '\n'.join(' '.join(map(str, l)) for l in sa)

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)

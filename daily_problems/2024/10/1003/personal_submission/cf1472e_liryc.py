'''
https://codeforces.com/contest/1472/submission/284111784
1472E
2024/10/3 Y1
1700
sorting
'''

import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n = int(input())
    h = [0] * n
    w = [0] * n
    for i in range(n):
        h[i], w[i] = map(int, input().split())
    return n, h, w

def solve(n: int, h: list[int], w: list[int]) -> str: # list[int]:
    ans = [-1] * n
    min_i, min_h = -1, 10**9 + 1
    for h1, _h2, i in sorted((min(x, y), -max(x, y), i) for i, (x, y) in enumerate(zip(h, w))):
        h2 = -_h2
        if min_h < h2:
            ans[i] = min_i + 1
        if h2 < min_h:
            min_h, min_i = h2, i
    return ' '.join(map(str, ans))

if __name__ == '__main__':
    for _ in range(int(input())):
        args = init()
        ans = solve(*args)
        print(ans)

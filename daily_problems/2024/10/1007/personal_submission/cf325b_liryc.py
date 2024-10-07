'''
https://codeforces.com/contest/325/submission/284715866
325B
2024/10/7 Y1
1800
math
'''

import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n = int(input())
    return n

def solve(n: int) -> list[int]:
    ans = []

    for t in range(60):
        d = (1 << t) - 1
        l, r = 1, 2 * 10 ** 9
        while l <= r:
            m = l + r >> 1
            c = m * (m - 1) // 2 + m * d
            if c < n:
                l = m + 1
            elif c > n:
                r = m - 1
            else:
                if m & 1:
                    ans.append(m * (d + 1))
                break
    if ans:
        ans.sort()
    else:
        ans.append(-1)
    return ans

if __name__ == '__main__':
    n = init()
    ans = solve(n)
    print(*ans, sep='\n')

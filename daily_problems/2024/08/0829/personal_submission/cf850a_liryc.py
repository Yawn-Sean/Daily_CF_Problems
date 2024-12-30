'''
https://codeforces.com/contest/850/submission/278584495
850 A
2024/8/29 Y1
1700
Brute Force + IQT
'''

from itertools import combinations
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n = int(input())
    a = []
    for _ in range(n):
        x1, x2, x3, x4, x5 = map(int, input().split())
        a.append((x1, x2, x3, x4, x5))
    return n, a

def solve(n: int, a):
    ans = []
    if len(a) > 33:
        return ans
    for i in range(n):
        good = True
        for j, k in combinations((r for r in range(n) if r != i), 2):
            if sum((x - z) * (y - z) for x, y, z in zip(a[j], a[k], a[i])) > 0:
                good = False
                break
        if good:
            ans.append(str(i + 1))
    return ans

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(len(ans))
    if ans:
        print(*ans, sep='\n')

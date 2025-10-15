'''
https://codeforces.com/problemset/submission/847/291176825
847E
2024/11/12 Y1
1800
DP+Binary Search
'''
# binary serach t, verify that can eat all in t time
from bisect import bisect_left
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n = int(input())
    s = input()
    return n, s

def solve(n: int, s: int):
    p, a = [], []
    for i, c in enumerate(s):
        if c == 'P':
            p.append(i)
        elif c == '*':
            a.append(i)
    def check(t):
        nonlocal n, p, a
        eat = -1
        for x in p:
            i = j = eat + 1
            while j < len(a):
                l, r = a[i], a[j]
                if abs(l - x) + abs(r - l) <= t or abs(r - x) + abs(l - r) <= t:
                    eat = j
                    j += 1
                else:
                    break
            if eat == len(a) - 1:
                return True
        return False            
    return bisect_left(range(n << 1), 1, key=check)

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)

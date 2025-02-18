'''
https://codeforces.com/contest/895/submission/282982813
895B
2024/9/26 Y1
1700
two pointers (enum left + binary search right)
'''

from bisect import bisect_left
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, x, k = map(int, input().split())
    a = list(map(int, input().split()))
    return n, x, k, a

def solve(n, x, k, a):
    ans = 0

    a.sort()
    for i, num in enumerate(a):
        l = (num - 1) // x + k
        ans += bisect_left(a, (l + 1) * x) - bisect_left(a, max(num, l * x))
    return ans

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)

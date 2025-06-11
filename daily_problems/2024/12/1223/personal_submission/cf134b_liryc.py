'''
https://codeforces.com/problemset/submission/134/298077240
134B
2024/12/23 Y2
1900
number theory
'''
# ref
from math import gcd
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n = int(input())
    return n

def rec(x, y):
    if x == 0: return -1
    d, m = divmod(y, x)
    return d + rec(m, x)

if __name__ == '__main__':
    n = init()
    print(min(rec(i, n) for i in range(1, n + 1) if gcd(i, n) == 1))

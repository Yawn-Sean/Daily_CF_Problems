'''
https://codeforces.com/gym/106415/submission/366491506
'''
# interactive problem

from functools import cache
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n = int(input())
    sa = list(map(int, input().split()))
    return n, sa

def query(n, m):
    print('?', n, m, flush=True)
    return int(input()[2:])

def answer(x):
    print('!', x, flush=True)
    return input()

@cache
def findf(x):
    if not x & x - 1:
        return query(x, x) // 2
    y = (1 << x.bit_length()) - x
    return query(y, x) - findf(y)

def solve(n: int, sa: list[int]) -> list[int]:
    return [findf(x) for x in sa]

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    for x in ans:
        answer(x)

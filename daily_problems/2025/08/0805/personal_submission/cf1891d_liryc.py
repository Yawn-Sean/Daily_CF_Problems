'''
1891D
2025/08/05 Y2
1900
math
'''
# enumerations
from sys import stdin
input = lambda: stdin.readline().strip()
pmax = lambda x, y: y if y > x else x
pmin = lambda x, y: y if y < x else x
# pmin = lambda x, y: y if x < 0 or y >= 0 and y < x else x

def init():
    l, r = map(int, input().split())
    return l, r

def solve(l: int, r: int) -> int:
    f = l.bit_length() - 1
    return -1

if __name__ == '__main__':
    for _ in range(int(input())):
        args = init()
        ans = solve(*args)
        print(ans)

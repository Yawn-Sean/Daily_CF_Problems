'''
https://codeforces.com/problemset/submission/1027/290574960
1027C
2024/11/8 Y1
1600
greedy
'''
# ref
from collections import Counter
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n = int(input())
    a = list(map(int, input().split()))
    return n, a

def solve(n: int, a: list[int]):
    cnt = Counter(a)
    b = []
    
    for k, v in cnt.items():
        if v >= 4:
            return f'{k} {k} {k} {k}'
        if v >= 2:
            b.append(k)
    
    b.sort()
    x, y = 1, 0
    for i in range(1, len(b)):
        nx, ny = b[i], b[i - 1]
        if nx * y < x * ny:
            x, y = nx, ny

    return f'{x} {x} {y} {y}'

if __name__ == '__main__':
    for _ in range(int(input())):
        args = init()
        ans = solve(*args)
        print(ans)

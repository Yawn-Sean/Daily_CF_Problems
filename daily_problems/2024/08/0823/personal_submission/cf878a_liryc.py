'''
https://codeforces.com/contest/878/submission/277722625
878 A
2024/8/23 Y1
1600
bit operation + constructive
'''

import sys
input = lambda: sys.stdin.readline().strip()

def solve():
    n = int(input())
    x1, x0, y1, y2, y3 = 1023, 0, 0, 1023, 0
    for _ in range(n):
        a = input().split()
        o, x = a[0], int(a[1])
        if o == '|':
            x1 |= x
            x0 |= x
        elif o == '&':
            x1 &= x
            x0 &= x
        else: # o == '^'
            x1 ^= x
            x0 ^= x
    for i in range(10):
        b = 1 << i
        b1, b2 = x1 & b, x0 & b
        if b1 and b2:
            y1 |= b
        elif not b1 and not b2:
            y2 ^= b
        elif not b1 and b2:
            y3 |= b
    return y1, y2, y3

if __name__ == '__main__':
    ans = solve()
    print(3)
    print('|', ans[0])
    print('&', ans[1])
    print('^', ans[2])
    

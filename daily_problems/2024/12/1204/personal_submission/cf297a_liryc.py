'''
https://codeforces.com/problemset/submission/297/294712673
CF297A
20241204 Y1
1700
string / bits / Parity
'''
# 脑筋急转弯？
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    s1 = input()
    s2 = input()
    return s1, s2

def solve(s1, s2):
    c1, c2 = s1.count('1'), s2.count('1')
    return c1 + (c1 & 1) >= c2

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print("YES" if ans else "NO")
'''
https://codeforces.com/problemset/submission/86/296229771
86 A
2024/12/13 Y1
1600
math
'''
# ref
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    l, r = map(int, input().split())
    return l, r
def solve(l: int, r: int):
    v = 10 ** len(str(r)) - 1
    mid = v >> 1
    if mid <= l: 
        return l * (v - l)
    elif mid >= r: 
        return r * (v - r)
    else: 
        return mid * (v - mid)

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)

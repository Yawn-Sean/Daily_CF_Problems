'''
https://codeforces.com/contest/1055/submission/279349541
1055C
2024/9/2 Y2
1900
math:裴蜀定理 
'''
from math import gcd

def init():
    la, ra, ta = map(int, input().split())
    lb, rb, tb = map(int, input().split())
    return la, ra, ta, lb, rb, tb

def solve(la, ra, ta, lb, rb, tb):
    a = ra - la + 1
    b = rb - lb + 1

    g = gcd(ta, tb)
    x = la - lb
    x %= g

    return max(0, min(x + a, b) - x, min(x - g + a, b))

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)

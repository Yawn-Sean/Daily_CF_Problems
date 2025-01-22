'''
https://codeforces.com/problemset/submission/2045/299239610
2045B
2025/01/01 Y2
2000
number theory
'''
# n d均除以s，n=min(n,d), 问题转化成寻找 1->n
# 若存在x满足n%x==0,即存在1->n/x->n (留意此时仍要判断n-n/x<=d，即增量是否在范围内)
# 否则n为奇数，存在1->(n-1)/2->n-1
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, d, s = map(int, input().split())
    return n, d, s

def solve(n: int, d: int, s: int):
    if s > d:
        return s
    n, d = n // s, d // s
    n = min(n, d << 1)
    if n - 1 <= d or n & 1 == 0:
        return n * s
    for x in range(2, int(n ** 0.5) + 1):
        if n % x == 0 and n - n // x <= d:
            return n * s
    return (n - 1) * s

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)

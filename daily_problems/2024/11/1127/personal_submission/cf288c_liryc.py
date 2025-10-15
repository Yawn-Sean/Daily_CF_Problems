'''
https://codeforces.com/problemset/submission/288/293528562
288C
2024/11/27 Y1
1700
math
'''
# ref
import sys
input = lambda: sys.stdin.readline().strip()

n = 0
ans = []

def init():
    global n, ans
    n = int(input())
    ans = list(range(n + 1))

def solve(l, r):
    global ans
    if l > r: return
    le = r - l + 1
    v = 1 << le.bit_length() - 1
    for i in range(l, r - v + 1):
        ans[i] ^= v
    for i in range(l + v, r + 1):
        ans[i] ^= v
    for i in range(r - v + 1, r + 1):
        ans[i] ^= v - 1
    solve(l, r - v)

if __name__ == '__main__':
    init()
    solve(0, n)
    print(n * (n + 1))
    print(*ans, sep='\n')


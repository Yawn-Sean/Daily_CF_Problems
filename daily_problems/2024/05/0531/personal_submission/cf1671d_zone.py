"""
question: https://codeforces.com/problemset/problem/1671/D
submission: https://codeforces.com/contest/1671/submission/263427307
"""

def solve():
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    res = sum(abs(x - y) for x, y in zip(a[:-1], a[1:]))
    res += min(min(a[0], a[-1]) - 1, 2 * min(a) - 2)
    res += max(0, min(x - max(a[0], a[-1]), 2 * x - 2 * max(a)))
    print(res)

for _ in range(int(input())):
    solve()

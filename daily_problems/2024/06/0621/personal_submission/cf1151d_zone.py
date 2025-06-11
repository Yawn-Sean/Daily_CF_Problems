"""
problem: https://codeforces.com/contest/1151/problem/D
submission: https://codeforces.com/contest/1151/submission/266647334
"""

def main():
    n = int(input())
    a, b = [], [] 
    for _ in range(n):
        x, y = map(int, input().split())
        a.append(x)
        b.append(y)
    c = sorted(zip(a, b), key=lambda x: x[1] - x[0])
    print(sum(x * (i - 1) + y * (n - i) for i, [x, y] in enumerate(c, 1)))

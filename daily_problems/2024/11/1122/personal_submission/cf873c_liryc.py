'''
https://codeforces.com/problemset/submission/873/292784371
873C
2024/11/22 Y1
1600
sliding window
'''
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, m, k = map(int, input().split())
    a = [[] for _ in range(m)]
    for _ in range(n):
        for i, x in enumerate(map(int, input().split())):
            a[i].append(x)
    return n, m, k, a

def solve(a: list[int], k: int):
    s, t = a[:k].count(1), 0
    ans = s
    for i in range(k, len(a)):
        s += a[i] - a[i - k]
        if s > ans:
            ans = s
            t = i - k + 1
    return ans, a[:t].count(1)

if __name__ == '__main__':
    n, m, k, a = init()
    s, c = 0, 0
    for aa in a:
        x, y = solve(aa, k)
        s += x
        c += y
    print(s, c)
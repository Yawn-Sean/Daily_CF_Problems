'''
https://codeforces.com/gym/104805/submission/337812421
'''
# DFS
from sys import stdin
input = lambda: stdin.readline().strip()

def init():
    n, l = map(int, input().split())
    a = list(map(int, input().split()))
    return n, l, a

def solve(n: int, l: int, a: list[int]) -> int:
    l += 1
    hs = set()
    stk = [(1, 0)]
    while stk:
        s, i = stk.pop()
        for j in range(i, n):
            t = s * (a[j] + 1)
            if t <= l and not t in hs:
                hs.add(t)
                stk.append((t, j))
    return len(hs)

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)

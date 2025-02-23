'''
https://codeforces.com/problemset/submission/671/295979558
671B
2024/12/11 Y2
2000
prefix sum
'''
# 计算前缀和和后缀和即可
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, k = map(int, input().split())
    c = list(map(int, input().split()))
    return n, k, c

def solve(n: int, k: int, c: list[int]) -> int:
    c.sort()
    a = 0 # a[i]: coins needed for c[i:] all become c[i]
    hi = c[-1] # coins the richest has
    for i in range(n - 2, -1, -1):
        d = (c[i + 1] - c[i]) * (n - i - 1)
        if a + d <= k:
            a += d
            hi = c[i]
            if a == k: break
        else:
            hi = c[i + 1] - (k - a) // (n - i - 1)
            break
    a = 0
    lo = c[0] # coins the poorest has
    for i in range(1, n):
        d = (c[i] - c[i - 1]) * i
        if a + d <= k:
            a += d
            lo = c[i]
            if a == k: break
        else:
            lo = c[i - 1] + (k - a) // i
            break

    return hi - lo if hi > lo else 1 if sum(c) % n else 0

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)

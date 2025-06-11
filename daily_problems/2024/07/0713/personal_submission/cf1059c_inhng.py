import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

def f(n):
    if n <= 3:
        return [1] * (n - 1) + [n]
    return [1] * (n - n // 2) + [x * 2 for x in f(n // 2)]

n = int(input())
print(' '.join(map(str, f(n))))

import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

n = int(input())
a, b = [], []
for _ in range(n):
    ai, bi = map(int, input().split())
    a.append(ai)
    b.append(bi)
idx = list(range(n))
idx.sort(reverse = True, key = lambda x: a[x] - b[x])
print(sum(i * a[idx[i]] + (n - i - 1) * b[idx[i]] for i in range(n)))

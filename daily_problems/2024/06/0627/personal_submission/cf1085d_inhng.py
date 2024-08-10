import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

n, s = map(int, input().split())
cnt = [0 for _ in range(n + 1)]
for _ in range(n - 1):
    a, b = map(int, input().split())
    cnt[a], cnt[b] = cnt[a] + 1, cnt[b] + 1
print(2 * s / cnt.count(1))

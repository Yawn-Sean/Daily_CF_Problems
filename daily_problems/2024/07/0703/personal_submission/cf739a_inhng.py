import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

n, m = map(int, input().split())
leng = n + 1
for _ in range(m):
    l, r = map(int, input().split())
    leng = min(leng, r - l + 1)
print(leng)
print(' '.join(str(i % leng) for i in range(n)))

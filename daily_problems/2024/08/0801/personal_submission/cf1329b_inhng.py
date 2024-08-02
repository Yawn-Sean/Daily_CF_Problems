import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

for _ in range(int(input())):
    d, m = map(int, input().split())
    ans, cnt = 1, 1
    while cnt <= d:
        ans = ans * (1 + min(cnt, d - cnt + 1)) % m
        cnt <<= 1
    print((ans - 1) % m)

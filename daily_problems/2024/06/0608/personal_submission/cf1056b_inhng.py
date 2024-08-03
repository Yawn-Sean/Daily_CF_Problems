import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

n, m = map(int, input().split())
ans = 0
for i in range(1, m + 1):
    cnt_i = (n + m - i) // m
    for j in range(1, m + 1):
        cnt_j = (n + m - j) // m
        if (pow(i, 2, m) + pow(j, 2, m)) % m == 0:
            ans += cnt_i * cnt_j
print(ans)

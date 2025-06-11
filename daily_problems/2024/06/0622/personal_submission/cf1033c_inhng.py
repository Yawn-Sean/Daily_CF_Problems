import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

n = int(input())
a = list(map(int, input().split()))
ans, idx = [0 for _ in range(n)], [0 for _ in range(n + 1)]
for i, ai in enumerate(a):
    idx[ai] = i
for i in range(n, 0, -1):
    for j in range(idx[i] % i, n, i):
        if a[j] > i and not ans[j]:
            ans[idx[i]] = 1
            break
print(''.join("BA"[i] for i in ans))

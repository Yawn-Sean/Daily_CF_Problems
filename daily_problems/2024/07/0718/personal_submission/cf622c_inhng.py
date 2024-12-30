import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

n, m = map(int, input().split())
a = [-1] + list(map(int, input().split()))
left = [i for i in range(n + 1)]
for i in range(1, n + 1):
    if a[i] == a[i - 1]:
        left[i] = left[i - 1]
for _ in range(m):
    l, r, x = map(int, input().split())
    if a[r] != x:
        print(r)
    elif left[r] > l:
        print(left[r] - 1)
    else:
        print(-1)

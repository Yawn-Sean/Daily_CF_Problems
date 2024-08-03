# https://codeforces.com/contest/573/submission/258324605
n = int(input())
a = list(map(int, input().split()))
from_left = [0] * n
from_right = [0] * n
for i in range(n):
    if i == 0:
        from_left[i] = 1
    else:
        from_left[i] = min(a[i], from_left[i - 1] + 1)
for i in range(n - 1, -1, -1):
    if i == n - 1:
        from_right[i] = 1
    else:
        from_right[i] = min(a[i], from_right[i + 1] + 1)
ret = 0
for l, r in zip(from_left, from_right):
    ret = max(ret, min(l, r))
print(ret)

'''
https://codeforces.com/problemset/submission/590/288992025
590A
2024/10/31 Y1
1700
counting
'''
from itertools import repeat
from sys import stdin
input = lambda: stdin.readline().strip()

n = int(input())
a = list(map(int, input().split()))
c, ans = 0, 0
for i in range(1, n):
    if i < n - 1 and a[i - 1] != a[i] != a[i + 1]:
        c += 1
    elif c:
        ans = max(ans, c + 1 >> 1)
        if c & 1:
            # 0 1 2 3 4  i=4 c=3
            # 1 0 1 0 1 -> 1 1 1 1 1
            a[i-c:i] = repeat(a[i], c)
        else:
            # 0 1 2 3 4 5 i=5 c=4
            # 0 1 0 1 0 1 -> 0 0 0 1 1 1
            a[i - c:i - c // 2] = repeat(a[i - c - 1], c >> 1)
            a[i - c // 2:i] = repeat(a[i], c >> 1)
        c = 0

print(ans)
print(' '.join(map(str, a)))

'''
https://codeforces.com/problemset/submission/364/293754895
364A
2024/11/29 Y1
1600
math
'''
# ref
from collections import Counter
t = int(input())
a = [int(c) for c in input()]
n = len(a)

cn = Counter()

for i in range(n):
    cur = 0
    for j in range(i, n):
        cur += a[j]
        cn[cur] += 1

if t == 0:
    sm = (n * (n + 1) // 2) ** 2
    sm -= (n * (n + 1) // 2 - cn[0]) ** 2
    print(sm)
else:
    ans = 0
    for i in range(1, 9 * n + 1):
        if t % i == 0 and t // i <= 9 * n:
            ans += cn[i] * cn[t // i]
    print(ans)
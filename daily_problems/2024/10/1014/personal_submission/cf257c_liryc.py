'''
https://codeforces.com/problemset/submission/257/285836532
257C
2024/10/14 Y1
1800
geometry
'''
# ref
from math import pi, atan2
if __name__ == '__main__':
    n = int(input())
    a = []

    for _ in range(n):
        x, y = map(int, input().split())
        a.append(atan2(y, x))

    a.sort()

    ans = 0
    for i in range(1, n):
        ans = max(ans, a[i] - a[i - 1])

    ans = min(2 * pi - ans, a[-1] - a[0]) / pi * 180.0
    print(ans) 
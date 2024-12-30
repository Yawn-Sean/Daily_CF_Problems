# submission link: https://codeforces.com/problemset/submission/1660/272636897

import sys
input = lambda: sys.stdin.readline().strip()

check = int(input())
for _ in range(check):
    emptyline = input()
    n = int(input())
    f = [0] * n
    for i in range(n):
        s = input()
        for j in range(n):
            f[j - i] += int(s[j])
    s = sum(f)
    mx = max(f)
    print(n - mx + s - mx)
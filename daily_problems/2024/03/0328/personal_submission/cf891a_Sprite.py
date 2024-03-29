from math import gcd
n = int(input())
a = list(map(int, input().split()))

if (m := a.count(1)):
    print(n - m)
else:
    ans = 2001
    for i in range(n):
        now = a[i]
        for j in range(i+1, n):
            now = gcd(now, a[j])
            if now == 1:
                ans = min(ans, j-i)
    print(ans + n - 1 if ans != 2001 else -1)

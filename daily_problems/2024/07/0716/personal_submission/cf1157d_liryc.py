'''
https://codeforces.com/contest/1157/submission/270903837
1157D
2024/7/16 Y2
1900
math
'''

n, k = map(int, input().split())
sm = (1 + k) * k >> 1
if n < sm:
    print("NO")
else:
    a = list(range(1, k + 1))
    r = k
    for i in range(k):
        if i > 0:
            a[i] = a[i - 1] + 1
            d = min(a[i - 1] * 2 - a[i], (n - sm) // r)
        else:
            d = (n - sm) // r
        a[i] += d
        sm += d * r
        r -= 1
    if sm == n:
        print("YES")
        print(*a)
    else:
        print("NO")

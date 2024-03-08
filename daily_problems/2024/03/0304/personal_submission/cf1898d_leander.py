import sys
input = lambda: sys.stdin.readline().strip()


t = int(input())
while t:
    t -= 1
    n = int(input())

    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    ans = 0
    l = []
    r = []
    for i in range(n):
        x, y = a[i], b[i]
        if x > y:
            x, y = y, x
        ans += y - x
        l.append(x)
        r.append(y)
    l.sort()
    r.sort()
    ans += 2 * max(0, l[-1] - r[0])
    print(ans)

import sys
input = lambda: sys.stdin.readline().rstrip()


def soviet():
    n = int(input())
    a = list(map(int, input().split()))

    mx = max(a)
    ans = 0

    if mx <= 1:
        print(0)
    elif n == 2:
        x, y = a[0], a[1]
        while x > 1 or y > 1:
            ans += x // 2 + y // 2
            x, y = (x & 1) + y // 2, (y & 1) + x // 2
        print(ans)
    else:
        ans = sum(a)
        print(1 if ans == 3 and mx == 3 else ans - 1)


MT = int(input())
for _ in range(MT):
    soviet()

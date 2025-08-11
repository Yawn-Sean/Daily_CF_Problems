def solve():
    import sys
    import math

    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    pos = [0] * (n + 1)
    for i in range(n):
        pos[a[i]] = i + 1
    minum = [10000000000] * (n + 1)
    for i in range(m):
        x, y = map(int, input().split())
        x = pos[x]
        y = pos[y]
        if x > y:
            y, x = x, y
        minum[x] = min(minum[x], y)
    ans = 0
    last = n + 1
    for i in range(n, 0, -1):
        last = min(last, minum[i])
        ans += last - i
    print(ans)


if __name__ == "__main__":
    solve()

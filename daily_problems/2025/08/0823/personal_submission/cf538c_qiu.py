def solve():
    import sys

    n, m = map(int, input().split())
    # ans = 0
    p = [None] * m
    for i in range(m):
        p[i] = tuple(map(int, input().split()))
    ok = False
    ans = p[0][1] + p[0][0] - 1
    for i in range(m - 1):
        next_d = p[i + 1][0]
        next_h = p[i + 1][1]
        d, h = p[i]
        len = abs(h - next_h)
        if next_d - d < len:
            ok = True
        else:
            t = int((next_d - d - len) // 2)
            ans = max(ans, t + max(next_h, h))
    ans = max(ans, p[m - 1][1] + n - p[m - 1][0])
    if ok:
        print("IMPOSSIBLE")
    else:
        print(ans)


if __name__ == "__main__":
    solve()

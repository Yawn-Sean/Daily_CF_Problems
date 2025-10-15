def solve():
    import sys

    n = int(input())
    ans = 0
    for i in range(1, n):
        if 2 * i + (i - 1) * i / 2 * 3 > n:
            break
        if (n - 2 * i) % 3 == 0:
            ans += 1
    print(ans)


if __name__ == "__main__":
    solve()

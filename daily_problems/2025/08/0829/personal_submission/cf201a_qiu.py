def solve():
    import sys

    n = int(input())
    if n == 3:
        print(5)
        return
    for i in range(50):
        num = ((2 * i + 1) * (2 * i + 1) + 1) // 2
        if num >= n:
            print(2 * i + 1)
            return


if __name__ == "__main__":
    solve()

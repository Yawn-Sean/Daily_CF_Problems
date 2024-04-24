def query(x, y):
    print("?", x, y, flush=True)
    return int(input())


def main():
    """
    (x1, y)
    (x2, y)

    x1 - 1 + y - 1 = d1
    1e9 - x2 + y - 1 = d2

    x1 = d1 - y + 2
    x2 = 1e9 + y - 1 - d2

    mid = (x1 + x2) // 2
        = (d1 - d2 + 1e9 + 1) // 2
    """
    d1 = query(1, 1)
    d2 = query(10 ** 9, 1)
    mid = (d1 - d2 + 10 ** 9 + 1) // 2
    y = query(mid, 1) + 1

    d3 = query(10 ** 9, 10 ** 9)
    x2 = 10 ** 9 + y - 1 - d2
    print("!", d1 - y + 2, y, x2, 10 ** 9 * 2 - x2 - d3)


main()

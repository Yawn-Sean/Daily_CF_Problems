# 一开始只通分了一次，错麻了，要通分两次
# abs(x / y - a / b) -> abs(x * b - y * a) / (b * y)
# abs(x / y - a / b) / (b * y) - ndiff_dividend / ndiff_divisor
def CF281B():
    x, y, n = MII()
    dividend, divisor = 0, 1
    diff_dividend, diff_divisor = x, y
    for b in range(1, n + 1):
        v = b * x // y
        for a in range(v, v + 2):
            ndiff_dividend, ndiff_divisor = abs(x * b - y * a), b * y
            if ndiff_dividend * diff_divisor < diff_dividend * ndiff_divisor:
                dividend, divisor = a, b
                diff_dividend, diff_divisor = ndiff_dividend, ndiff_divisor
    print(f"{dividend}/{divisor}")

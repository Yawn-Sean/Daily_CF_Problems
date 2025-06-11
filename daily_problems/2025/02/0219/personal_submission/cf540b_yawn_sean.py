# Submission link: https://codeforces.com/contest/540/submission/306805624
def main():
    n, k, p, x, y = MII()
    nums = LII()

    c1 = 0
    total = 0

    for v in nums:
        if v >= y: c1 += 1
        total += v

    v_to_add = fmax((n + 1) // 2 - c1, 0)

    if n - k < v_to_add or v_to_add * y + (n - k - v_to_add) + total > x:
        print(-1)
    else:
        print(*([1] * (n - k - v_to_add) + [y] * v_to_add))
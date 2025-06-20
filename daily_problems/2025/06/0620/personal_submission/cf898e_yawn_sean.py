# Submission link: https://codeforces.com/contest/898/submission/325212921
def main():
    n = II()
    nums = LII()

    c1 = 0
    c0 = 0

    for v in nums:
        x = math.isqrt(v)
        if x * x == v:
            c1 += 1
        else:
            c0 += 1


    tmp = []

    if c1 > c0:
        for v in nums:
            x = math.isqrt(v)
            if x * x == v:
                tmp.append(1 if x else 2)
    else:
        for v in nums:
            x = math.isqrt(v)
            if x * x < v:
                tmp.append(fmin(v - x * x, (x + 1) * (x + 1) - v))

    tmp.sort()

    print(sum(tmp[:abs(c0 - n // 2)]))
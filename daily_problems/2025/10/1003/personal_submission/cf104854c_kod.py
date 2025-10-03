t = ix()
for i in range(t):
    p = ix()
    ans = set()
    for b in range(1, 10**6):
        if (p - 1) % (b + 1) == 0 and 2 * (p - 1) % (b + 2) == 0:
            ans.add(b)
    for k in range(1, 2 * 10 ** 6):
        if 2 * (p - 1) % k == 0:
            v = 2 * (p - 1) // k
            b = (-3 + isqrt(1 + 4 * v)) // 2
            if b > 0 and (p - 1) % (b + 1) == 0 and 2 * (p - 1) % (b + 2) == 0:
                ans.add(b)

    ans = sorted(ans)
    print(len(ans))
    print(*ans)

def solve(p, x, y, a):
    mod = p * (p - 1)
    invx = pow(x, p - 2, p)
    cur = 1
    ans = 0
    for t in range(p - 1):
        # k ≡ c (mod p)
        c = y * cur % p
        # c + p*m ≡ t (mod p-1)
        inv_p = pow(p, -1, p - 1)
        m = (t - c) * inv_p % (p - 1)
        k0 = c + p * m
        if k0 >= 1 and k0 <= a:
            ans += 1 + (a - k0) // mod
        cur = cur * invx % p

    return ans
p, x, y, a = map(int, input().split())
print(solve(p, x, y, a))

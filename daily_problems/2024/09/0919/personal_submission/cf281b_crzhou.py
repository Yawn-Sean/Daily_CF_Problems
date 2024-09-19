x, y, n = MII()
ansa = ansb = 0

ans = 1e5
for b in range(1, n + 1):
    tmp1 = b * x // y
    tmp2 = b * x // y + 1
    l = lcm(b, y)
    if x * l // y - tmp1 * l // b <= tmp2 * l // b - x * l // y:
        if x * l // y - tmp1 * l // b < ans * l:
            ans = x / y - tmp1 / b
            ansa = tmp1
            ansb = b
    else:
        if tmp2 * l // b - x * l // y < ans * l:
            ans = tmp2 / b - x / y
            ansa = tmp2
            ansb = b

g = gcd(ansa, ansb)
ansa //= g
ansb //= g
print(ansa, "/", ansb, sep="")

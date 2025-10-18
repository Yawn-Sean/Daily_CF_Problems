n = ix()
a = il()
t = gcd(a[0], a[1])
for i in range(n):
    if a[i] % t != 0:
        exit(print('NO'))
    a[i] //= t
v = set()
p = PrimeTable(max(a))
for x in a:
    if x != 1:
        f = p.get_prime_factor_list(x)
        for y in f:
            if y in v:
                exit(print('NO'))
            v.add(y)
print('YES')

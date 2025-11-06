a, op, b = iis()
aa = 0
for d in a:
    aa = (10 * aa + int(d)) % mod
bb = 0
for d in b:
    bb = (10 * bb + int(d)) % (mod if op != '^' else mod - 1)
if op == '+':
    print((aa + bb) % mod)
elif op == '-':
    print((aa - bb) % mod)
elif op == '*':
    print((aa * bb) % mod)
else:
    print(pow(aa, bb, mod))

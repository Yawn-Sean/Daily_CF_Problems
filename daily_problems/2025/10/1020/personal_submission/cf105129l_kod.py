p = PrimeTable(50)
res = [1]
for x in p.primes:
    for i in range(len(res)):
        res.append(res[i] * x)
res.sort()

t = ix()
for i in range(t):
    n = ix()
    a = il()
    v = set(a)
    for x in res:
        for y in v:
            if gcd(x, y) == 1:
                break
        else:
            print(x)
            break

def factors(n):
    return [i for i in range(1, int(n**0.5) + 1) if n % i == 0] + [
        n // i for i in reversed(range(1, int(n**0.5) + 1)) if n % i == 0
    ]


lst = [-1] * 100005
n = II()
for i in range(n):
    a, b = MII()
    res = 0
    for f in factors(a):
        if lst[f] + b < i:
            res += 1
        lst[f] = i
    print(res)

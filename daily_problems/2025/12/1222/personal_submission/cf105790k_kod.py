def mul(a, b, mod) :
    return [[sum(x * y for x, y in zip(row, col)) % mod for col in zip(*b)] for row in a]

def mpow(a, n, mod):
    size = len(a)
    res = [[0] * size for _ in range(size)]
    for i in range(size):
        res[i][i] = 1
    while n:
        if n & 1:
            res = mul(res, a, mod)
        a = mul(a, a, mod)
        n >>= 1
    return res

n = ix()
print(pow(2, mpow([[1, 1], [1, 0]], n, mod - 1)[0][1], mod))





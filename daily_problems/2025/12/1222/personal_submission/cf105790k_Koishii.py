mod = 998244352

def fib(n):
    if n == 0: return (0, 1)
    a, b = fib(n >> 1)
    c = a * (2 * b - a) % mod
    d = (a * a + b * b) % mod
    if n & 1: return (d, c + d)
    else: return (c, d)

print(pow(2, fib(int(input()))[0], mod + 1))

def soviet():
    a = int(input())
    b = int(input())
    c = int(input())
    d = int(input())

    if a == b:
        if c != d:
            return 0
        y = 2 * c // (2 * a + 1)
        return c - a * y

    if (c - d) % (a - b): return 0
    k = (c - d) // (a - b)
    if k < 0: return 0
    x = c - a * k
    if x < (k + 1) // 2: return 0
    return x

print(soviet())

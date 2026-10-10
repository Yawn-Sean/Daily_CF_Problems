t = ix()
for i in range(t):
    n = ix()
    print(n // 3 * 2 + 1 - (n % 3 == 0) if n > 2 else 0)

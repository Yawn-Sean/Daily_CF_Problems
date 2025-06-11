a, b = map(int, input().split())

mod = 10 ** 9 + 7
print(((a * (a + 1) // 2 * b + a) * b * (b - 1) // 2) % mod)

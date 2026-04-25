mod = 10 ** 9 + 7

outs = []
for _ in range(int(input())):
    n = int(input())
    n1 = (n + 1) // 2
    n0 = n - n1
    outs.append((n0 * n1 * (n1 - 1) // 2 + n0 * (n0 - 1) * (n0 - 2) // 6) % mod)

print('\n'.join(map(str, outs)))

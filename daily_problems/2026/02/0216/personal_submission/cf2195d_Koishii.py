def soviet():
    n = int(input())
    f = [0] + list(map(int, input().split()))
    tot = (f[1] + f[n]) // (n - 1)
    a = [0] * (n + 1)

    pre = 0
    for i in range(1, n):
        a[i] = (f[i + 1] - f[i] + tot - 2 * pre) // 2
        pre += a[i]

    a[n] = tot - sum(a)

    print(*a[1:])

for _ in range(int(input())):
    soviet()

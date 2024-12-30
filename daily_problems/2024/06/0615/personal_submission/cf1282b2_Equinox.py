T = int(input())

for _ in range(T):
    N, p, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    f = [p + 1] * (N + 1)
    f[0] = 0
    res = 0
    for i in range(1, N + 1):
        if i < k:
            f[i] = a[i - 1] + f[i - 1]
        else:
            f[i] = f[i - k] + a[i - 1]
        if p >= f[i]:
            res = i
    print(res)
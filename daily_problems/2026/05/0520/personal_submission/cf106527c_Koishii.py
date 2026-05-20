outs = []
for _ in range(int(input())):
    n, q, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort(reverse = True)

    def check(x):
        b = a[:]
        for i in range(q):
            b[i] = max(0, b[i] - x)
        return sum(b) <= k * (n - x)


    l, r = 0, n
    while l < r:
        mid = l + r >> 1
        if check(mid): r = mid
        else: l = mid + 1
    outs.append(l)

print('\n'.join(map(str, outs)))

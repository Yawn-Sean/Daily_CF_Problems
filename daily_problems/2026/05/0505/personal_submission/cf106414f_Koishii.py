outs = []
def soviet():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))

    for i in range(n):
        a[i] = (a[i], i)

    a.sort(key = lambda x: x[0])
    while a and a[-1][0] >= 2 * m: a.pop()

    for k in range(len(a) - 1, 1, -1):
        if a[k][0] * 3 < m: break
        l, r = 0, k - 1
        while l < r:
            mid = l + r >> 1
            if a[mid][0] + a[mid + 1][0] + a[k][0] >= m:
                r = mid
            else:
                l = mid + 1

        i, j = l, l + 1
        now = a[i][0] + a[j][0] + a[k][0]
        if j < k and now >= m and now <= 2 * m:
            outs.append(' '.join(map(str, (a[i][1] + 1, a[j][1] + 1, a[k][1] + 1))))
            return

    outs.append(-1)


for _ in range(int(input())):
    soviet();
print('\n'.join(map(str, outs)))

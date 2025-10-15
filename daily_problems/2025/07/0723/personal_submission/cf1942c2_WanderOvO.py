T = int(input())
while T > 0:
    T -= 1
    n, x, y = map(int, input().split())
    a = list(map(int, input().split()))

    for i in range(x):
        a[i] -= 1
    a.sort()

    res = x
    segs = []
    for i in range(1, x):
        cnt = a[i] - a[i - 1] - 1
        if cnt % 2 != 0:
            segs.append(cnt)

    if (a[0] + n - a[-1] - 1) % 2 != 0:
        segs.append(a[0] + n - a[-1] - 1)
    segs.sort()
    for i in range(len(segs)):
        cnt = segs[i]
        if cnt // 2 <= y:
            y -= cnt // 2
            res += cnt

    res = min(n, res + y * 2)
    print(res - 2)

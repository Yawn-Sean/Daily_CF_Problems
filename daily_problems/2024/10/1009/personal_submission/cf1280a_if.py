mod = 10 ** 9 + 7
for _ in range(int(input())):
    x = int(input())
    s = input()
    n = len(s)
    o = 1
    cnt = 0
    ids = [0] * x
    for i in range(min(x, n)):
        ids[i] = int(s[i])
    cur = min(x, n)
    cur -= 1
    for i in range(x):
        cnt += (n - 1 - i) * (ids[i] - 1)
        n += cnt
        n %= mod
        c = cnt
        while cur < x - 1 and cnt:
            cnt -= 1
            ids[cur + 1] = ids[i + c - cnt]
            cur += 1

        cnt = 0

    print(n)

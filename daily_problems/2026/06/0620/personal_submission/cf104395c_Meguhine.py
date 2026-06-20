from sys import stdout

write = stdout.write

n, K = map(int, input().split())
s = list(input())

if n == 1:
    write(s[0] * K)
    exit()
elif n == 2:
    x, y = s[0], s[1]
    if x > y:
        x, y = y, x
    write(x * K)
    write(y * K)
    exit()

p_mn = 0
for i in range(1, n):
    if s[i] < s[p_mn]:
        p_mn = i
if p_mn != 0:
    f = p_mn & 1
    idx = ([0] if f else []) + list(range(f, n, 2))
    idx.sort(key=lambda x: s[x])
    for x in idx:
        if (x == 0 and f) or (x == n - 1):
            write(s[x] * K)
        else:
            write((s[x] + s[x + 1]) * K)
else:
    p_mn = 1
    for i in range(2, n):
        if s[i] < s[p_mn]:
            p_mn = i
    if p_mn != 1:
        idx = list(range(1, n, 2))
        idx.sort(key=lambda x: s[x])
        write(s[0] * K)
        for x in idx:
            if x == n - 1:
                write(s[x] * K)
            else:
                write((s[x] + s[x + 1]) * K)
    else:
        idx = list(range(1, n))
        idx.sort(key=lambda x: s[x])
        write(s[0] * K)
        write(s[1])
        for x in idx:
            times = K - 1 if x & 1 else 1
            if x == n - 1:
                write(s[x] * times)
            else:
                write((s[x] + s[x + 1]) * times)

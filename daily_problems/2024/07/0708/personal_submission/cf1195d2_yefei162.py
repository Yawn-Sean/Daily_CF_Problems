import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: int(input())
LI = lambda: list(MI())
mod = 998244353

tcn = 1
for _tcn_ in range(tcn):
    n = I()
    A = LI()

    cnt = [0] * 11
    for a in A:
        s = list(str(a))
        cnt[len(s)] += 1

    tot = 0
    for a in A:
        s = list(str(a))
        m = len(s)
        for i in range(1, 11):
            s.insert(max(0, m - i + 1), '0')
            x = int(''.join(s))
            tot += x * cnt[i]
            tot %= mod

    for a in A:
        s = list(str(a))
        m = len(s)
        for i in range(1, 11):
            s.insert(max(0, m - i), '0')
            x = int(''.join(s))
            tot += x * cnt[i]
            tot %= mod

    print(tot)

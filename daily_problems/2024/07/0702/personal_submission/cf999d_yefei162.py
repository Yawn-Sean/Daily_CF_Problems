import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())

tcn = 1
for _tcn_ in range(tcn):
    n, m = MI()
    A = LI()
    c = n // m
    cnt = [[] for _ in range(m)]
    for i, a in enumerate(A):
        r = a % m
        cnt[r].append((a, i))

    i1 = 0
    i2 = m - 1
    for i in range(m):
        if len(cnt[i]) < c:
            while i1 < i and len(cnt[i]) < c:
                if len(cnt[i1]) > c:
                    cnt[i].append(cnt[i1].pop())
                else:
                    i1 += 1

            while i2 > i and len(cnt[i]) < c:
                if len(cnt[i2]) > c:
                    cnt[i].append(cnt[i2].pop())
                else:
                    i2 -= 1
    # for i in range(m):
    #     print(len(cnt[i]), end=' ')
    # print()

    B = [0] * n
    for r in range(m):
        for x, i in cnt[r]:
            if x % m == r:
                B[i] = x
            else:
                target = x // m * m + r
                if target < x:
                    target += m
                B[i] = target
    tot = sum(y - x for x, y in zip(A, B))
    print(tot)
    print(*B)

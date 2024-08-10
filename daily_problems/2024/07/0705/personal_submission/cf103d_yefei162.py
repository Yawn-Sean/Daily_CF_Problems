import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())


tcn = 1
for _tcn_ in range(tcn):
    n = I()
    A = LI()
    m = I()
    groups = [[] for _ in range(n + 1)]
    for j in range(m):
        a, b = MI()
        a -= 1
        groups[b].append((a, j))

    ans = [0] * m
    K = min(n, 500)
    for d in range(n, K, -1):
        for a, j in groups[d]:
            i = a
            while i < n:
                ans[j] += A[i]
                i += d

    B = [0] * n
    for d in range(K, 0, -1):
        if not groups[d]:
            continue
        for i in range(n):
            B[i] = A[i]
        for i in range(n - d - 1, -1, -1):
            B[i] += B[i + d]

        for a, j in groups[d]:
            ans[j] = B[a]

    print('\n'.join(str(x) for x in ans))

import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: int(input())

A = [1] + [10 ** i for i in range(1, 13)]
B = [0] + [9 * 10 ** i for i in range(12)]

tcn = 1
for _tcn_ in range(tcn):
    k = I()
    L, R = 1, 10 ** 12
    ans = 0
    bi = 1
    while L <= R:
        mid = (L + R) // 2
        c = 0
        for i in range(1, 13):
            if mid >= A[i]:
                c += i * B[i]
            else:
                c += i * (mid - A[i - 1] + 1)
                break
        # print(c)
        if c < k:
            ans = mid
            bi = k - c
            L = mid + 1
        else:
            R = mid - 1

    print(str(ans + 1)[bi - 1])

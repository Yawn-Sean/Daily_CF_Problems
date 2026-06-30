import sys

input = lambda: sys.stdin.readline().rstrip()


n, K = map(int, input().split())
a = list(map(int, input().split()))
idx_1 = sorted(range(0, n, 2), key=lambda x: -a[x])
idx_2 = sorted(range(1, n, 2), key=lambda x: -a[x])
c1, c2 = 0, 0
i, j, s = 0, 0, 0
for k in range(K, 0, -1):
    if input() == "2":
        c2 += 1
        print(idx_2[j] + 1, flush=True)
        s += a[idx_2[j]]
        j += 1
    else:
        c1 += 1
        if a[idx_1[i]] >= a[idx_2[j + k - 1]]:
            print(idx_1[i] + 1, flush=True)
            s += a[idx_1[i]]
            i += 1
        else:
            print(idx_2[j] + 1, flush=True)
            s += a[idx_2[j]]
            j += 1
    assert input() == "1"

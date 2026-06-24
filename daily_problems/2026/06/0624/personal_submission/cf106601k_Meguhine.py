import sys
from array import array

input = lambda: sys.stdin.readline().rstrip()


N = 10**6 + 5
ds = [array('i', [1, x]) for x in range(N)]
ds[0] = array('i', [])
ds[1] = array('i', [1])
for x in range(2, N):
    for y in range(x << 1, N, x):
        ds[y].append(x)

n, Q = map(int, input().split())
a = list(map(int, input().split()))

cnt = array('i', [0] * N)
for x in a:
    cnt[x] += 1
ans = array('i', [0] * N)
for x in cnt:
    for d in ds[x]:
        ans[d] += 1

outs = []
for _ in range(Q):
    v = list(map(int, input().split()))
    if v[0] == 1:
        i, y = v[1] - 1, v[2]
        x = a[i]
        for d in ds[cnt[x]]:
            ans[d] -= 1
        for d in ds[cnt[y]]:
            ans[d] -= 1
        cnt[x] -= 1
        cnt[y] += 1
        for d in ds[cnt[x]]:
            ans[d] += 1
        for d in ds[cnt[y]]:
            ans[d] += 1
        a[i] = y
    else:
        outs.append(ans[v[1]])
print('\n'.join(map(str, outs)))

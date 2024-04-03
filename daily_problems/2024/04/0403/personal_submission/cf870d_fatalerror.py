import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())

def query(i, j):
    print('?', i, j, flush=True)
    return ii()

n = ii()
qp = [-1] * n
qb = [-1] * n
qp[0] = qb[0] = query(0, 0)
for i in range(1, n):
    qp[i] = query(i, 0)
for i in range(1, n):
    qb[i] = query(0, i)

cnt = 0
ans = []
for x in range(n):
    p = [-1] * n
    b = [-1] * n
    p[0] = x

    for i in range(n):
        b[i] = p[0] ^ qb[i]
    for i in range(n):
        p[i] = b[0] ^ qp[i]

    if all(bi < n and p[bi] == i for i, bi in enumerate(b)):
        cnt += 1
        ans = p

print('!')
print(cnt)
print(*ans)

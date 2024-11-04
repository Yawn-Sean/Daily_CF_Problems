n, m = map(int, input().split())
a = [[] for i in range(m)]
for _ in range(n):
    s, r = map(int, input().split())
    a[s - 1].append(r)
b = []
for i in a:
    if i:
        b.append(i)
for i in range(len(b)):
    b[i].sort(key = lambda x : -x)
b.sort(key = lambda x: -len(x))
for i in range(len(b)):
    for j in range(1, len(b[i])):
        b[i][j] += b[i][j - 1]
cnt = [0 for i in range(len(b[0]))]
for i in b:
    for j in range(len(i)):
        cnt[j] += max(0, i[j])
print(max(cnt))


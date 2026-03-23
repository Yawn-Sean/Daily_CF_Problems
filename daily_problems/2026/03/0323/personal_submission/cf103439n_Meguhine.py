n = int(input()) << 1
a = [sorted(map(int, input().split())) for _ in range(n)]
idx = sorted(range(n), key=lambda x: a[x][0] + a[x][1])
print(sum(map(lambda x: a[x][1], idx[n >> 1:])) - sum(map(lambda x: a[x][0], idx[:n >> 1])))

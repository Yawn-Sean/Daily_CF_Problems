idx = 0
n = int(data[idx])
m = int(data[idx + 1])
q = int(data[idx + 2])
idx += 3

w = list(map(int, data[idx:idx + n]))
idx += n
N = 1 << n
cnt = [0] * N
cur = [0] * N
sum_matrix = [[0] * 101 for _ in range(N)]

for _ in range(m):
    s = data[idx]
    idx += 1
    cur_value = int(s, 2)
    cnt[cur_value] += 1

for i in range(N):
    for j in range(n):
        if i & (1 << j):
            cur[i] += w[n - j - 1]

for i in range(N):
    for j in range(N):
        s_value = cur[i ^ j ^ (N - 1)]
        if s_value <= 100:
            sum_matrix[i][s_value] += cnt[j]

for i in range(N):
    for j in range(1, 101):
        sum_matrix[i][j] += sum_matrix[i][j - 1]

output = []
for _ in range(q):
    s = data[idx]
    k = int(data[idx + 1])
    idx += 2
    cur_value = int(s, 2)
    output.append(sum_matrix[cur_value][k])

print('\n'.join(map(str, output)))

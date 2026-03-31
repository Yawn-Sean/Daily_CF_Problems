n = int(input())
p = [0] * n
for i in range(n):
    p[i] = tuple(map(int, input().split()))

vis = [[False] * n for _ in range(n)]
states = []

def check(i, j):
    now = (1 << i) | (1 << j)
    vis[i][j] = True
    for k in range(j + 1, n):
        if k == i or k == j:
            continue
        if (p[j][1] - p[i][1]) * (p[k][0] - p[j][0]) == (p[k][1] - p[j][1]) * (p[j][0] - p[i][0]):
            now |= 1 << k
            vis[i][k] = vis[j][k] = True
    return now


for i in range(n):
    for j in range(i + 1, n):
        if vis[i][j]: continue
        states.append(check(i, j))

dp = [n] * (1 << n)
dp[0] = 0

for i in range(len(states)):
    for j in range(1 << n):
        dp[states[i] | j] = min(dp[states[i] | j], dp[j] + 1)

print(dp[(1 << n) - 1])

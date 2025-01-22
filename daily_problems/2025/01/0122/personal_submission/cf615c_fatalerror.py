s1 = [ord(ch)-97 for ch in input()]
s2 = s1[::-1]
t = [ord(ch)-97 for ch in input()]
if set(t) - set(s1):
    exit(print(-1))
m, n = len(s1), len(t)
dp = [[0] * (n+1) for _ in range(m+1)]
for i in range(m-1, -1, -1):
    for j in range(n-1, -1, -1):
        if s1[i] == t[j]:
            dp[i][j] = dp[i+1][j+1] + 1
        else:
            dp[i][j] = 0
match1 = [0] * n
lengths1 = [0] * n
for j in range(n):
    match1[j] = max(range(m), key=lambda i: dp[i][j])
    lengths1[j] = dp[match1[j]][j]

dp = [[0] * (n+1) for _ in range(m+1)]
for i in range(m-1, -1, -1):
    for j in range(n-1, -1, -1):
        if s2[i] == t[j]:
            dp[i][j] = dp[i+1][j+1] + 1
        else:
            dp[i][j] = 0
match2 = [0] * n
lengths2 = [0] * n
for j in range(n):
    match2[j] = max(range(m), key=lambda i: dp[i][j])
    lengths2[j] = dp[match2[j]][j]

ans = []
j = 0
while j < n:
    i1, i2 = match1[j], match2[j]
    l1, l2 = lengths1[j], lengths2[j]
    if l1 > l2:
        ans.append((i1+1, i1+l1))
        j += l1
    else:
        ans.append((m-i2, m+1-i2-l2))
        j += l2
print(len(ans))
for p in ans:
    print(*p)
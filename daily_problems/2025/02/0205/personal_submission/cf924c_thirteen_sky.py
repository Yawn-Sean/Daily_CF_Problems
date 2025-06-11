n = II()
m = LII()

t = [0] * (n + 1)
for i in range(1, n + 1):
    t[i] = max(t[i - 1], m[i - 1] + 1)
for i in range(n - 1, 0, -1):
    if t[i] < t[i + 1] - 1:
        t[i] = t[i + 1] - 1
ans = 0
for i in range(1, n + 1):
    ans += (t[i] - m[i - 1] - 1)

print(ans)

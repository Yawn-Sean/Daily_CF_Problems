n = int(input())
s = [0] * (n + 2)
g = [0] * (n + 2)
s2 = [0] * (n + 2)
sum = 0

s2[0] = s2[n + 1] = float('inf')

for i in range(1, n + 1):
    s[i], g[i] = map(int, input().split())
    s2[i] = s[i] + g[i]

for i in range(1, n + 1):
    s2[i] = min(s[i] + g[i], min(s2[i - 1] + 1, s2[i + 1] + 1))
    if s2[i] < s[i]:
        print(-1)
        exit()

for i in range(n, 0, -1):
    s2[i] = min(s[i] + g[i], min(s2[i - 1] + 1, s2[i + 1] + 1))
    if s2[i] < s[i]:
        print(-1)
        exit()

for i in range(1, n + 1):
    sum += s2[i] - s[i]

print(sum)
for i in range(1, n + 1):
    print(s2[i], end=' ')

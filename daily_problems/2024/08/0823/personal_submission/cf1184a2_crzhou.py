n = int(input())
s = input()

f = []
bc = defaultdict(list)
p = [0] * (n + 1)
ans = 0

for i in range(1, n + 1):
    if n % i == 0:
        bc[i] = [0] * i
        f.append(i)

for i in range(len(s)):
    for it in f:
        bc[it][i % it] ^= int(s[i]) - 0

for it in f:
    for j in range(it):
        p[it] |= bc[it][j]

for i in range(1, n + 1):
    if not p[gcd(i, n)]:
        ans += 1

print(ans)

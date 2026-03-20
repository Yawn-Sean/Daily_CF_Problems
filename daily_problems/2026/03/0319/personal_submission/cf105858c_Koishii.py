mod = 998244353

a = input()
b = input()

if len(a) < len(b):
    a, b = b, a

c = a + b
c = sorted(c)
i = len(c) - 1
sa = []
sb = []

while i >= 0:
    sa.append(c[i])
    i -= 1
    if i <= (len(b) - 1) * 2:
        sb.append(c[i])
        i -= 1

ans = 0
for i in range(len(sa)):
    ans = (ans * 10 + int(sa[i])) % mod
    if len(sa) - i <= len(sb):
        ans += int(sb[i - len(sa) + len(sb)])

print(ans % mod)

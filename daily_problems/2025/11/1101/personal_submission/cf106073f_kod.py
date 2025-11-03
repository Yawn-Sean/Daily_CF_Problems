n, q = il()
x = il()
ans = [0] * (n + 1)
t = 0
for c in x[::-1]:
    ans[c] = (ans[c] + t * 500000004) % mod
    t = (t + c) * 500000004 % mod
ans[1] = (ans[1] + t) % mod
print(*ans[1:], sep="\n")

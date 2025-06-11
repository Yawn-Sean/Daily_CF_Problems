x, y = MII()
ans = 0
es = [y] * 3
i = 0
while min(es) < x:
    es[i] = fmin(x, es[i - 2] + es[i - 1] - 1)
    i += 1
    i %= 3
    ans += 1
print(ans)

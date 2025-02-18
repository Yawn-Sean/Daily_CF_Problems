n = RI()
ans = 0
f2, f1 = 2, 1
while f2 <= n:
    ans += 1
    f2, f1 = f2 + f1, f2
print(ans)

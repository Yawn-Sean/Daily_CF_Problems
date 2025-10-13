n = ix()
a = il()
ans = 1
c = -1
t = 0
for x in a:
    c += 1
    if x > t:
        t = x
        ans = ans * (c + 1) % mod
        c = 0
print(ans)

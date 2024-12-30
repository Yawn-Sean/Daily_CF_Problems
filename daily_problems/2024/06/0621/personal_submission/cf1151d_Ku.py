n = RI()
a,b,c = [], [], []
for _ in range(n):
    x,y = RII()
    a.append(x)
    b.append(y)
    c.append(x-y)
c.sort(reverse = True)
ans = n * sum(b) - sum(a)
for i,x in enumerate(c):
    ans += x * (i + 1)
print(ans)

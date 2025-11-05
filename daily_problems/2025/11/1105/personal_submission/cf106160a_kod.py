n = [int(x) for x in input()]
k = len(n)
ans = v = 0
c = 1
for i in range(k - 1):
    v += n[i] * c
    ans += v
    c /= 10
v += n[-1] * c
print(ans * 0.9 + v)

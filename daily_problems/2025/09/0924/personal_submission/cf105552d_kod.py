n, r = il()
ans = 0
for i in range(n):
    a, b, c = il()
    d = abs(c) / sqrt(a * a + b * b)
    ang = acos(d / r)
    ans = max(ans, (ang * r * r - sqrt(r * r - d * d) * d) / (pi * r * r))
print(ans, 1 - ans)

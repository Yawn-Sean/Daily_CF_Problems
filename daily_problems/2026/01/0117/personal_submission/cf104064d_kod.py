n = ix()
a = c = -inf
b = d = inf
for x, y in [il() for _ in range(n)]:
    a = max(a, x + y)
    b = min(b, x + y)
    c = max(c, x - y)
    d = min(d, x - y)
if a == b and c == d:
    print(4)
elif a == b or c == d:
    print(a - b + c - d + 5)
else:
    print(a - b + c - d + 4)

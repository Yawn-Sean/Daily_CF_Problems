n, k, q = il()
a = il()
b = [-1] * n
for i in range(n):
    if a[i] & k == k:
        b[i] = a[i] - k
s = LST(b, -1, -1, op, app, com)
for i in range(q):
    l, r = il()
    if s.query(l - 1, r - 1) == 0:
        print("YES")
    else:
        print("NO")

n, l, r = il()
a = il()
c = min(l - 1, n - r)
a = a if c == 0 else a[:-c]
sl = sorted(a)
print(sum(sl[-(r - l + 1):]))

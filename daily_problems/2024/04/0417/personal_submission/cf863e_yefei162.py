n = I()
segments = [LI() for _ in range(n)]
st = set()
for s, e in segments:
    st.add(s)
    st.add(e)
    st.add(s - 1)
    st.add(e + 1)

v2i = {v: i for i, v in enumerate(sorted(st))}

N = len(st)
op = min
e = 10 ** 6
mapping = lambda f, x: x + f
composition = lambda f, g: f + g
id_ = 0
Lst = LazySegmentTree(N, op, e, mapping, composition, id_)
for i in range(N):
    Lst.set(i, 0)

for l, r in segments:
    l, r = v2i[l], v2i[r]
    Lst.apply(l, r + 1, 1)

# for i in range(N):
#     print(Lst.prod(i, i + 1), end=' ')
# print()

ans = -1
for i in range(n):
    l, r = segments[i]
    l, r = v2i[l], v2i[r]
    if Lst.prod(l, r + 1) >= 2:
        ans = i + 1
        break
print(ans)


n,m,k = il()
a = il()
op = il()

pos = [-1] * (n + 1)
for i, x in enumerate(a):
    pos[x] = i

# print(pos)
ans = 0
for x in op:
    ans += (pos[x] + k ) // k
    pp = pos[x] - 1
    if pp < 0:
        continue
    ppx = a[pp]
    pos[x] -= 1
    a[pp] = x
    pos[ppx] += 1
    a[pos[ppx]] = ppx
print(ans)

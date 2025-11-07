def fun(p):
    m = len(p)
    pi = [0] * m
    c = 0
    for i in range(1, m):
        v = p[i]
        while c and p[c] != v:
            c = pi[c - 1]
        if p[c] == v:
            c += 1
        pi[i] = c
    return pi

M = 10 ** 4
n, m = il()
nums1 = il()
nums2 = il()
vals = []
for i in range(1, m):
    vals.append((nums2[i] - nums2[i - 1]) % M)
vals.append(-1)
for i in range(1, n):
    vals.append((nums1[i] - nums1[i - 1]) % M)
kmp = fun(vals)

cnt = [0] * M
ma = 0
for i in range(m, n + m - 1):
    if kmp[i] == m - 1:
        v = (nums2[0] - nums1[i - 2 * (m - 1)]) % M
        cnt[v] += 1
        if ma < cnt[v]:
            ma = cnt[v]

print(cnt.index(ma), ma)

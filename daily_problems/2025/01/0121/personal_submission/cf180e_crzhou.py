n, m, k = MII()
a = LII()

num_idx = {}
for i, x in enumerate(a):
    if x not in num_idx:
        num_idx[x] = []
    num_idx[x].append(i)

ans = 0
for idxs in num_idx.values():
    j = 0 
    for i in range(len(idxs)):
        while idxs[i] - idxs[j] - (i - j) > k:
            j += 1
        ans = fmax(ans, i - j + 1)

print(ans)

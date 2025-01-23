mii = lambda: map(int, input().split())

n, m, k = mii()
mp = [[] for _ in range(m)]
for i, x in enumerate(mii()):
    mp[x-1].append(i)

ans = 0
for pos in mp:
    l = 0
    for r, x in enumerate(pos):
        while x - pos[l] > r - l + k:
            l += 1
        ans = max(ans, r-l+1)
print(ans)
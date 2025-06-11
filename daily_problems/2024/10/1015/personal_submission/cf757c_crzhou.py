n, m = MII()
vc = defaultdict(list)
ans = 1
MOD = 10 ** 9 + 7

for idx in range(1, n + 1):
    _, *nums = MII()
    for a in nums:
        vc[a].append(idx)

mp = defaultdict(int)

for i in range(1, m + 1):
    mp[tuple(vc[i])] += 1
    ans = ans * mp[tuple(vc[i])] % MOD

print(ans)

# https://codeforces.com/contest/757/submission/286010123
mod = 10**9 + 7
n, m = RII()
cnt = [['0'] for _ in range(m + 1)]
for i in range(1, n + 1):
    for x in RILIST()[1:]:
        cnt[x].append(str(i))
ans = 1
mp = defaultdict(int)
for i in range(1, m + 1):
    t = '#'.join(cnt[i])
    sh = StringHash(t).get_hash(0, len(t))
    mp[sh] += 1
    ans = ans * mp[sh] % mod
print(ans)
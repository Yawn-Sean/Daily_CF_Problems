n, k = RII()
a = RLIST()
cnt = Counter()
for x in a:
    cnt[x] += 1
if k == 0:
    print(sum(x * (x - 1) // 2 for x in cnt.values()))
else:
    ans = 0
    val = [i for i in range(1 << 14) if bin(i).count('1') == k]
    for i in range(1 << 14):
        if cnt[i] > 0:
            for x in val:
                ans += cnt[i] * cnt[i ^ x]
    print(ans // 2)

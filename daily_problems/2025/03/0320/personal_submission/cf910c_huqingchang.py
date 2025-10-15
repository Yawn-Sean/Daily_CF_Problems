def main():
    n = II()
    cnt = Counter()
    mul = [1, 10, 100, 1000, 10000, 100000]
    first_ch_ban = set()
    for _ in range(n):
        s = I()
        first_ch_ban.add(s[0])
        for i, j in enumerate(s[::-1]):
            cnt[j] += mul[i]
    candi = list(cnt.keys())
    candi.sort(key=lambda p: cnt[p])
    girls = deque(list(range(1, 10)))
    ans = 0
    tmp = []
    while candi:
        a = candi.pop()
        if a not in first_ch_ban:
            break
        tmp.append(a)
    candi.extend(tmp[::-1])
    while candi:
        a = candi.pop()
        b = girls.popleft()
        ans += cnt[a] * b
    return ans


T = 1
for ii in range(T):
    print(main())

def main():
    s = [ord(ch) - ord('a') for ch in I()]
    n = len(s)
    ans = 0
    res = [[] for _ in range(26)]
    for i, j in enumerate(s):
        res[j].append(i)
    for i in range(26):
        if not res[i]:
            continue
        tmp = 0
        for p in range(n):
            cnt = [0] * 26
            for j in res[i]:
                cnt[s[(j + p) % n]] += 1
            tmp = fmax(tmp, cnt.count(1))
        ans += tmp
    return ans / n


T = 1
for ii in range(T):
    print(main())

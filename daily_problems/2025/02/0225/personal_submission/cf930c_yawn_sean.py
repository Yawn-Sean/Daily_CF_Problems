# Submission link: https://codeforces.com/contest/930/submission/307599297
def main():
    n, m = MII()
    cnt = [0] * (m + 2)

    for _ in range(n):
        l, r = MII()
        cnt[l] += 1
        cnt[r + 1] -= 1

    for i in range(m + 1):
        cnt[i + 1] += cnt[i]

    v1 = [0] * (m + 2)
    v2 = [0] * (m + 2)

    tmp = []
    for i in range(1, m + 1):
        p = bisect.bisect_right(tmp, cnt[i])
        if p == len(tmp): tmp.append(cnt[i])
        else: tmp[p] = cnt[i]
        v1[i] = len(tmp)

    tmp = []
    for i in range(m, 0, -1):
        p = bisect.bisect_right(tmp, cnt[i])
        if p == len(tmp): tmp.append(cnt[i])
        else: tmp[p] = cnt[i]
        v2[i] = len(tmp)

    ans = 0
    for i in range(m + 1):
        ans = fmax(ans, v1[i] + v2[i + 1])

    print(ans)
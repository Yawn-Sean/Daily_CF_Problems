def main():
    n, m = MII()
    res = LII()
    need = [0] + LII()
    tot = sum(need)
    cnt = [0] * (m + 1)
    for x in res:
        cnt[x] += 1
    if any(cnt[i] < need[i] for i in range(1, m + 1)):
        return -1
    r_bound = -1
    for r in range(n - 1, -1, -1):
        cnt[res[r]] -= 1
        if cnt[res[r]] < need[res[r]]:
            r_bound = r
            cnt[res[r]] += 1
            break
    ans = r_bound + 1
    for l in range(1, n):
        cnt[res[l - 1]] -= 1
        while cnt[res[l - 1]] < need[res[l - 1]]:
            r_bound += 1
            if r_bound >= n:
                return ans - tot
            cnt[res[r_bound]] += 1
        ans = min(ans, r_bound - l + 1)
    return ans - tot


T = 1
for ii in range(T):
    print(main())

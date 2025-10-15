# Submission link: https://codeforces.com/problemset/submission/958/308723395
def main():
    n, m = MII()
    nums = LGMI()
    cnt = LII()

    l, r = 0, 0
    c = 0
    total = 0

    for i in range(m):
        if cnt[i] == 0:
            c += 1
        total += cnt[i]

    ans = n + 5

    while l < n:
        while r < n and c < m:
            cnt[nums[r]] -= 1
            if cnt[nums[r]] == 0:
                c += 1
            r += 1
        
        if c < m: break
        ans = fmin(ans, r - l)
        
        if cnt[nums[l]] == 0:
            c -= 1
        cnt[nums[l]] += 1
        l += 1

    print(ans - total if ans <= n else -1)
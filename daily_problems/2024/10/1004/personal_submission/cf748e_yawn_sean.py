# Submission link: https://codeforces.com/contest/748/submission/284241423
def main():
    n, k = MII()
    nums = LII()

    M = 10 ** 7

    cnt = [0] * (M + 1)
    for num in nums:
        cnt[num] += 1

    cur = 0
    for i in range(M, 0, -1):
        cur += cnt[i]
        
        if i * 2 + 1 <= M:
            cur += cnt[i * 2 + 1]
            cnt[i] += cnt[i * 2 + 1]
            cnt[i + 1] += cnt[i * 2 + 1]
        
        if i * 2 <= M:
            cur += cnt[i * 2]
            cnt[i] += cnt[i * 2] * 2
        
        if cur >= k:
            exit(print(i))

    print(-1)
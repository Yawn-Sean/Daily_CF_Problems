def main():
    n, t = MII()
    l, r = MII()
    nums = LII()

    cnt = [0] * (10 ** 5 + 1)
    for x in nums:
        cnt[x] += 1
    
    total = 0
    v = t
    for i in range(1, 10 ** 5 + 1):
        d = fmin(cnt[i], v // i)
        total += d
        v -= d * i
        cnt[i] = d

    dp = [-n] * (r + 1)
    for i in range(min(r, v) + 1):
        dp[i] = 0

    ndp = [-n] * (r + 1)
    que = [0] * (r + 1)
    vals = [0] * (r + 1)

    for i in range(r, -1, -1):
        if cnt[i]:
            for j in range(r + 1):
                vals[j] = (j - l) // i + 1 if j >= l else 0
            
            for j in range(i):
                left, right = 0, 0
                for k in range(j, r + 1, i):
                    if left < right and que[left] < k - i * cnt[i]:
                        left += 1
                    while left < right and dp[que[right - 1]] - vals[que[right - 1]] <= dp[k] - vals[k]:
                        right -= 1
                    que[right] = k
                    right += 1
                    
                    ndp[k] = dp[que[left]] - vals[que[left]] + vals[k]
        
            for j in range(r + 1):
                dp[j] = ndp[j]

    print(total * 10 ** 6 + max(dp))
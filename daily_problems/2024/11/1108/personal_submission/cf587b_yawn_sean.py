# Submission link: https://codeforces.com/contest/587/submission/290473709
def main():
    n, l, k = MII()
    nums = LII()
    mod = 10 ** 9 + 7

    if k == 1:
        print(l % mod)
        exit()

    st_range = sorted(range(n), key=lambda x: nums[x])
    dp = [0] * (n * k)

    ans = 0
    for i in range(k):
        pt = 0
        cur = 0
        
        for j in st_range:
            idx = i * n + j
            
            if i == 0: dp[idx] = 1
            else:
                while pt < n and nums[st_range[pt]] <= nums[j]:
                    cur += dp[(i - 1) * n + st_range[pt]]
                    if cur >= mod:
                        cur -= mod
                    pt += 1
                
                dp[idx] = cur
            
            times = l // n - i
            if l % n > j: times += 1

            if times > 0:
                ans += times % mod * dp[idx] % mod
                if ans >= mod: ans -= mod

    print(ans)

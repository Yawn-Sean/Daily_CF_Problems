# Submission link: https://codeforces.com/contest/1310/submission/257107167
def main():
    n = II()
    nums = LII()
    time = LII()

    hpq = []
    tot = 0
    last_t = 0

    ans = 0
    for i in sorted(range(n), key=lambda x: nums[x]):
        for _ in range(nums[i] - last_t):
            if len(hpq) == 0: break
            tot += heappop(hpq)
            ans += tot
        
        heappush(hpq, -time[i])
        tot += time[i]
        last_t = nums[i]

    while hpq:
        tot += heappop(hpq)
        ans += tot

    print(ans)
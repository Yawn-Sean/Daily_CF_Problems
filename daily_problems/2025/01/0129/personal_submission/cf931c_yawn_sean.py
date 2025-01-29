# Submission link: https://codeforces.com/contest/931/submission/303449111
def main():
    n = II()
    nums = LII()

    mi = min(nums)
    cnt = [0] * 3

    for x in nums:
        cnt[x - mi] += 1

    ans = n
    chosen = 0
    
    if cnt[2]:
        ncnt = [0] * 3
        for i in range(-(cnt[1] // 2), fmin(cnt[0], cnt[2]) + 1):
            ncnt[0] = cnt[0] - i
            ncnt[1] = cnt[1] + 2 * i
            ncnt[2] = cnt[2] - i
            
            v = 0
            for j in range(3):
                v += fmin(cnt[j], ncnt[j])
            
            if v < ans:
                ans = v
                chosen = i

    cnt[0] -= chosen
    cnt[1] += 2 * chosen
    cnt[2] -= chosen

    print(ans)
    print(*([mi] * cnt[0] + [mi + 1] * cnt[1] + [mi + 2] * cnt[2]))
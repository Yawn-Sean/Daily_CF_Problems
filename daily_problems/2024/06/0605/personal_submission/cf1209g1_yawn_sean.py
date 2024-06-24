# Submission link: https://codeforces.com/contest/1209/submission/264188729
def main():
    n, q = MII()
    nums = LII()

    next_pos = [n] * n
    pos = [n] * (2 * 10 ** 5 + 1)
    cnt = [0] * (2 * 10 ** 5 + 1)

    for i in range(n - 1, -1, -1):
        next_pos[i] = pos[nums[i]]
        pos[nums[i]] = i
        cnt[nums[i]] += 1

    ans = 0

    l = r = 0
    ma = 0

    for i in range(n):
        if r < i:
            ans += r - l + 1 - ma
            l = r = i
            ma = 0
        
        if next_pos[i] > r and next_pos[i] < n:
            r = next_pos[i]
        if cnt[nums[i]] > ma:
            ma = cnt[nums[i]]

    ans += r - l + 1 - ma

    print(ans)
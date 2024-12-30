# Submission link: https://codeforces.com/contest/1163/submission/259287295
def main():
    n = II()
    nums = LII()

    cnt = [0] * (10 ** 5 + 1)
    freq_cnt = [0] * (n + 1)
    freq_cnt[0] = n

    ans = 0
    max_freq = 0

    for i, v in enumerate(nums, 1):
        freq_cnt[cnt[v]] -= 1
        cnt[v] += 1
        freq_cnt[cnt[v]] += 1

        max_freq = max(max_freq, cnt[v])
        
        if freq_cnt[i] == 1 or max_freq == 1 or \
            max_freq * freq_cnt[max_freq] == i - 1 or \
            (max_freq - 1) * (freq_cnt[max_freq - 1] + 1) == i - 1:
            ans = i

    print(ans)
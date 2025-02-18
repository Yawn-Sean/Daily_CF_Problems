# Submission link: https://codeforces.com/contest/847/submission/285243128
def main():
    n = II()
    nums = LII()

    pref_tot = [0] * n
    pref_val = [0] * n

    for i in range(n - 1):
        pref_val[i + 1] = fmax(pref_val[i] + 1, nums[i])
        pref_tot[i + 1] = pref_tot[i] + pref_val[i + 1] - nums[i]

    suff_tot = [0] * n
    suff_val = [0] * n

    for i in range(n - 1, 0, -1):
        suff_val[i - 1] = fmax(suff_val[i] + 1, nums[i])
        suff_tot[i - 1] = suff_tot[i] + suff_val[i - 1] - nums[i]

    ans = 10 ** 15
    for i in range(n):
        ans = fmin(ans, pref_tot[i] + suff_tot[i] + fmax(fmax(pref_val[i], suff_val[i]) + 1 - nums[i], 0))

    print(ans)
# Submission link: https://codeforces.com/contest/297/submission/324312505
def main():
    n = II()
    nums = LII()

    order = sorted(range(n), key=lambda x: nums[x])

    k1 = (n + 2) // 3
    k2 = n - k1

    ans1 = [0] * n
    ans2 = [0] * n

    for i in range(k1):
        ans1[order[i]] = i
        ans2[order[i]] = nums[order[i]] - ans1[order[i]]

    for i in range(k1, k2):
        ans2[order[i]] = i
        ans1[order[i]] = nums[order[i]] - ans2[order[i]]

    for i in range(k2, n):
        ans2[order[i]] = n - 1 - i
        ans1[order[i]] = nums[order[i]] - ans2[order[i]]

    print('YES')
    print(' '.join(map(str, ans1)))
    print(' '.join(map(str, ans2)))
# Submission link: https://codeforces.com/problemset/problem/626/D
def main():
    n = II()
    nums = LII()
    cnt = [0] * 5000

    for i in range(n):
        for j in range(i):
            cnt[abs(nums[i] - nums[j])] += 1

    cnt2 = [0] * 5000
    for i in range(5000):
        for j in range(5000):
            if i + j < 5000:
                cnt2[i + j] += cnt[i] * cnt[j]

    for i in range(1, 5000):
        cnt2[i] += cnt2[i-1]

    ans = 0
    for i in range(1, 5000):
        ans += cnt[i] * cnt2[i-1]

    print(ans / (n * (n - 1) / 2) ** 3)
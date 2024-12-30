# Submission link: https://codeforces.com/contest/309/submission/281800681
def main():
    n, l, t = MII()
    nums = LII()

    t *= 2

    ans = 0

    # 任意两个人，跑的总距离 2t
    # 设两人相向而行的位置差 = d
    # k = [2t / l]
    # k: d > 2t - k * l
    # k + 1: d <= 2t - k * l

    k, d = divmod(t, l)
    ans = n * (n - 1) * k

    for i in range(n):
        nums.append(nums[i] + l)

    for i in range(n):
        ans += bisect.bisect_right(nums, nums[i] + d) - i - 1

    print(ans / 4)
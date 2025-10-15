# Submission link: https://codeforces.com/contest/353/submission/315642973
def main():
    n = II()
    nums = LII()

    cnt = Counter(nums)
    st_range = sorted(range(2 * n), key=lambda x: (cnt[nums[x]], nums[x]))

    cols = [1] * (2 * n)
    for i in range(n):
        cols[st_range[2 * i]] = 2

    print(len({nums[i] for i in st_range[::2]}) * len({nums[i] for i in st_range[1::2]}))
    print(' '.join(map(str, cols)))
# Submission link: https://codeforces.com/contest/954/submission/259072779
def main():
    n, T = MII()

    nums = LII()
    temp = LII()

    for i in range(n):
        temp[i] -= T

    ans = sum(nums)
    tot_temp = sum(nums[i] * temp[i] for i in range(n))

    st_range = sorted(range(n), key=lambda x: temp[x])

    if tot_temp > 0:
        for i in range(n - 1, -1, -1):
            idx = st_range[i]
            if nums[idx] * temp[idx] <= tot_temp:
                ans -= nums[idx]
                tot_temp -= nums[idx] * temp[idx]
            else:
                ans -= tot_temp / temp[idx]
                tot_temp = 0
            if tot_temp == 0: break

    elif tot_temp < 0:
        tot_temp = -tot_temp
        for i in range(n):
            idx = st_range[i]
            if nums[idx] * (-temp[idx]) <= tot_temp:
                ans -= nums[idx]
                tot_temp -= nums[idx] * (-temp[idx])
            else:
                ans -= tot_temp / (-temp[idx])
                tot_temp = 0
            if tot_temp == 0: break

    print(ans)
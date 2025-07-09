# Submission link: https://codeforces.com/contest/260/submission/328167614
def main():
    n, x = MII()
    nums = LII()

    x -= 1
    mn = min(nums)

    for i in range(n):
        nums[i] -= mn

    mn *= n

    while nums[x]:
        nums[x] -= 1
        mn += 1
        x = (x - 1) % n

    nums[x] = mn

    print(*nums)
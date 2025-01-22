# Submission link: https://codeforces.com/contest/174/submission/293287459
def main():
    n = II()
    nums = LII()
    nums.append(0)

    for i in range(n, 0, -1):
        nums[i] -= nums[i - 1]

    ls = []
    rs = []

    for i in range(n + 1):
        if nums[i] >= 0:
            ls.extend(i + 1 for _ in range(nums[i]))
        else:
            rs.extend(i for _ in range(-nums[i]))

    k = len(ls)
    print(k)
    print('\n'.join(f'{ls[i]} {rs[i]}' for i in range(k)))
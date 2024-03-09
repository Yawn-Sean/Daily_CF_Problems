import collections


def main():
    n = int(input())
    nums = map(int, input().split())

    if n == 1:
        return -1

    if n == 2:
        return 1

    nums = sorted(enumerate(nums), key=lambda x: x[1])
    diff = collections.Counter()
    for idx, (i, v) in enumerate(nums[:-1]):
        diff[nums[idx+1][1] - v] += 1

    for idx, (i, v) in enumerate(nums):
        d1, d2, a = 0, 0, 0
        if idx == 0:
            d1 = nums[idx+1][1] - v
        elif idx == n - 1:
            d1 = v - nums[idx-1][1]
        else:
            d1, d2, a = nums[idx+1][1] - v, v - nums[idx-1][1], nums[idx+1][1] - nums[idx-1][1]

        diff[a] += 1
        diff[d1] -= 1
        diff[d2] -= 1
        if diff[d1] == 0:
            del diff[d1]
        if diff[d2] == 0:
            del diff[d2]

        if len(diff) == 1:
            return i + 1

        diff[a] -= 1
        diff[d1] += 1
        diff[d2] += 1
        if diff[a] == 0:
            del diff[a]

    return -1

print(main())

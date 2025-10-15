# Submission link: https://codeforces.com/contest/416/submission/302816051
def main():
    n = II()
    nums = LII()

    start = 0
    i1 = i2 = -1

    ans = 1

    for i in range(n):
        if nums[i] == -1:
            if i2 != -1:
                v = nums[i1] + (nums[i2] - nums[i1]) // (i2 - i1) * (i - i1)
                if v <= 0:
                    ans += 1
                    start = i
                    i1 = -1
                    i2 = -1
        else:
            if i1 == -1: i1 = i
            elif i2 == -1:
                if (nums[i] - nums[i1]) % (i - i1) or nums[i1] + (nums[i] - nums[i1]) // (i - i1) * (start - i1) <= 0:
                    ans += 1
                    start = i
                    i1 = i
                    i2 = -1
                else:
                    i2 = i
            else:
                v = nums[i1] + (nums[i2] - nums[i1]) // (i2 - i1) * (i - i1)
                if nums[i] != v:
                    ans += 1
                    start = i
                    i1 = i
                    i2 = -1

    print(ans)
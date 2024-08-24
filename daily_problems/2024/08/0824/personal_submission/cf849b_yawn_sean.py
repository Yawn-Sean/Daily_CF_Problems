# Submission link: https://codeforces.com/contest/849/submission/277849680
def main():
    n = II()
    nums = LII()

    for i in range(3):
        for j in range(i):
            k = (nums[i] - nums[j]) * 2 // (i - j)
            vis = set()
            for idx in range(n):
                vis.add(nums[idx] * 2 - idx * k)
                if len(vis) > 2:
                    break
            if len(vis) == 2:
                print('Yes')
                exit()

    print('No')
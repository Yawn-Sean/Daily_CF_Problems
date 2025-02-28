# Submission link: https://codeforces.com/contest/660/submission/306151277
def main():
    n, k = MII()
    nums = LII()

    l, r = 0, 0
    v = 0

    ans = -1
    choice = -1

    while l < n:
        while r < n and v + 1 - nums[r] <= k:
            v += 1 - nums[r]
            r += 1
        
        if r - l > ans:
            ans = r - l
            choice = l
        
        v -= 1 - nums[l]
        l += 1

    for i in range(ans):
        nums[choice + i] = 1

    print(ans)
    print(' '.join(map(str, nums)))
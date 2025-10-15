# Submission link: https://codeforces.com/contest/83/submission/314309080
def main():
    n, k = MII()
    nums = LII()

    if sum(nums) < k:
        print(-1)
    else:
        l, r = 0, 10 ** 9
        while l <= r:
            m = (l + r) // 2
            v = 0
            for x in nums:
                v += fmin(x, m)
            if v <= k:
                l = m + 1
            else:
                r = m - 1
        
        tmp = []
        for i in range(n):
            if nums[i] > r:
                tmp.append(i)
            k -= fmin(nums[i], r)
            nums[i] -= fmin(nums[i], r)
        
        for i in range(k):
            nums[tmp[i]] -= 1
        
        ans = []
        for i in range(k, len(tmp)):
            if nums[tmp[i]]:
                ans.append(tmp[i] + 1)
        
        for i in range(k):
            if nums[tmp[i]]:
                ans.append(tmp[i] + 1)
        
        print(' '.join(map(str, ans)))
# Submission link: https://codeforces.com/contest/1923/submission/330004674
def main():
    t = II()
    outs = []

    for _ in range(t):
        n = II()
        nums = LII()
        
        acc = list(accumulate(nums, initial=0))
        
        last_pos = list(range(n + 1))
        for i in range(1, n):
            if nums[i] == nums[i - 1]:
                last_pos[i] = last_pos[i - 1]
        
        next_pos = list(range(n + 1))
        for i in range(n - 2, -1, -1):
            if nums[i] == nums[i + 1]:
                next_pos[i] = next_pos[i + 1]
        
        ans = [n] * n
        
        for i in range(n):
            if i:
                l, r = 0, i - 1
                while l <= r:
                    mid = (l + r) // 2
                    if acc[i] - acc[mid] > nums[i]:
                        l = mid + 1
                    else:
                        r = mid - 1
                r = fmin(r, last_pos[i - 1] - 1)
                
                if r >= 0: ans[i] = fmin(ans[i], i - r)
                if nums[i - 1] > nums[i]: ans[i] = 1

            if i + 1 < n:
                l, r = i + 1, n - 1
                while l <= r:
                    mid = (l + r) // 2
                    if acc[mid + 1] - acc[i + 1] > nums[i]:
                        r = mid - 1
                    else:
                        l = mid + 1
                l = fmax(l, next_pos[i + 1] + 1)
                
                if l < n: ans[i] = fmin(ans[i], l - i)
                if nums[i + 1] > nums[i]: ans[i] = 1
            
            if ans[i] == n: ans[i] = -1
        
        outs.append(' '.join(map(str, ans)))

    print('\n'.join(outs))
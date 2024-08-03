# Submission link: https://codeforces.com/contest/613/submission/255803458
def main():
    n, a, cf, cm, m = MII()
    nums = LII()

    st_range = sorted(range(n), key=lambda x: nums[x])
    acc = list(accumulate((nums[i] for i in st_range), initial=0))

    equal = full = -1

    for i in range(n + 1):
        tot = i * a - (acc[n] - acc[n-i])
        if tot > m: break
        if i == n:
            new_equal = a
            new_full = n
        else:
            resid = m - tot
            
            l, r = 1, n - i
            while l <= r:
                mid = (l + r) // 2
                if nums[st_range[mid-1]] * mid - acc[mid] <= resid:
                    l = mid + 1
                else:
                    r = mid - 1
            
            new_equal = min(a, nums[st_range[r-1]] + (resid - (nums[st_range[r-1]] * r - acc[r])) // r)
            new_full = i
        
        if new_equal * cm + new_full * cf >= equal * cm + full * cf:
            equal = new_equal
            full = new_full

    print(equal * cm + full * cf)
    for i in range(n):
        if nums[i] < equal:
            nums[i] = equal

    for i in range(full):
        nums[st_range[n - 1 - i]] = a

    print(' '.join(map(str, nums)))
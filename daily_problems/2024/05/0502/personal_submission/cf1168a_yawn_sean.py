# Submission link: https://codeforces.com/contest/1168/submission/259071648
def main():
    n, m = MII()
    nums = LII()

    l, r = 0, m - 1
    while l <= r:
        mid = (l + r) // 2
        
        last_val = 0
        f = True
        for num in nums:
            if num < last_val:
                if mid < last_val - num:
                    f = False
                    break
            else:
                if num + mid >= m and num + mid - m >= last_val:
                    continue
                last_val = num
        
        if f: r = mid - 1
        else: l = mid + 1

    print(l)
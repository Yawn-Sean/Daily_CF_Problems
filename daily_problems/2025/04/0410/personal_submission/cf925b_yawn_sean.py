# Submission link: https://codeforces.com/contest/925/submission/314818097
def main():
    n, x1, x2 = MII()
    nums = LII()

    st_range = sorted(range(n), key=lambda x: nums[x])

    for i in range(n):
        c1 = (x1 + nums[st_range[i]] - 1) // nums[st_range[i]]
        if i + c1 < n and nums[st_range[i + c1]] * (n - i - c1) >= x2:
            print('Yes')
            print(c1, n - i - c1)
            print(' '.join(str(st_range[idx] + 1) for idx in range(i, i + c1)))
            print(' '.join(str(st_range[idx] + 1) for idx in range(i + c1, n)))
            exit()
        
        c2 = (x2 + nums[st_range[i]] - 1) // nums[st_range[i]]
        if i + c2 < n and nums[st_range[i + c2]] * (n - i - c2) >= x1:
            print('Yes')
            print(n - i - c2, c2)
            print(' '.join(str(st_range[idx] + 1) for idx in range(i + c2, n)))
            print(' '.join(str(st_range[idx] + 1) for idx in range(i, i + c2)))
            exit()

    print('No')
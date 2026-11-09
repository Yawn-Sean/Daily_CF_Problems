# Submission link: https://codeforces.com/gym/106611/submission/397947004
def main():
    n = II()
    nums = LII()
    
    if all(nums[i] > nums[i - 1] for i in range(1, 3 * n)):
        print(0)
        exit()
    
    l = 3 * n
    r = 0
    
    for i in range(3 * n):
        if nums[i] != i + 1:
            l = fmin(l, i)
            r = fmax(r, i)
    
    if r - l < 2 * n:
        print(1)
        print(l + 1, r + 1)
        exit()
    
    ma_left = 0
    
    for i in range(l, 3 * n):
        if nums[i] <= r - 2 * n + 1:
            ma_left = fmax(ma_left, i)
    
    if ma_left - l < 2 * n:
        print(2)
        print(l + 1, ma_left + 1)
        print(r - 2 * n + 2, r + 1)
        exit()
    
    mi_right = 3 * n
    
    for i in range(r + 1):
        if nums[i] >= l + 2 * n + 1:
            mi_right = fmin(mi_right, i)
    
    if r - mi_right < 2 * n:
        print(2)
        print(mi_right + 1, r + 1)
        print(l + 1, l + 2 * n)
        exit()
    
    print(3)
    print(1, 2 * n)
    print(n + 1, 3 * n)
    print(1, 2 * n)
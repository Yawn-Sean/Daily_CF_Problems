# Submission link: https://codeforces.com/contest/201/submission/335808737
def main():
    n = II()
    nums = LII()
    
    left0 = [0] * n
    left1 = [0] * n
    
    for i in range(n - 1):
        if nums[i] > 1:
            left1[i + 1] = left1[i] + nums[i] // 2 * 2
        left0[i + 1] = fmax(left0[i] + nums[i] - (nums[i] + 1) % 2, left1[i] + nums[i])
    
    right0 = [0] * n
    right1 = [0] * n
    
    for i in range(n - 2, -1, -1):
        if nums[i] > 1:
            right1[i] = right1[i + 1] + nums[i] // 2 * 2
        right0[i] = fmax(right0[i + 1] + nums[i] - (nums[i] + 1) % 2, right1[i + 1] + nums[i])
    
    print(fmax(max(left0[i] + right1[i] for i in range(n)),
            max(left1[i] + right0[i] for i in range(n))))
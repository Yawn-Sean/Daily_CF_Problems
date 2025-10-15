# Submission link: https://codeforces.com/contest/160/submission/334530465
def main():
    n, k = MII()
    nums = LII()
    nums.sort()
    
    k -= 1
    
    i = 0
    while i < n:
        j = i
        while j < n and nums[i] == nums[j]:
            j += 1
        
        if (j - i) * n > k:
            break
        
        k -= (j - i) * n
        i = j
    
    print(nums[i], nums[k // (j - i)])
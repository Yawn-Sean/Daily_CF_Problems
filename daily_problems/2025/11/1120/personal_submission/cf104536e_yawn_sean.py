# Submission link: https://codeforces.com/gym/104536/submission/349718798
def main(): 
    n = II()
    nums1 = LII()
    nums2 = LII()
    
    vals = []
    
    for i in range(n):
        if nums1[i] > nums2[i]:
            vals.append(nums1[i])
            vals.append(nums2[i])
        else:
            vals.append(nums2[i])
            vals.append(nums1[i])
    
    print(lengthOfLIS(vals))
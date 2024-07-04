# Submission Link: https://codeforces.com/contest/1672/submission/268690930
def main():
    n = II()
    nums1 = LII()
    nums2 = LII()
    
    saved = [0] * (n + 1)
    pt = 0
    
    for num in nums1:
        if num == nums2[pt]: pt += 1
        else: saved[num] += 1
        while pt < n and pt > 0 and nums2[pt] == nums2[pt-1] and saved[nums2[pt]]:
            saved[nums2[pt]] -= 1
            pt += 1
    
    return pt == n
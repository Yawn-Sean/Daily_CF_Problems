# Submission link: https://codeforces.com/contest/67/submission/332167610
def main():
    n = II()
    nums1 = LGMI()
    nums2 = LGMI()
    
    pos1 = [0] * n
    pos2 = [0] * n
    
    for i in range(n):
        pos1[nums1[i]] = i
        pos2[nums2[i]] = i
    
    ar = [0] * n
    
    for i in range(n):
        ar[pos1[i]] = -pos2[i]
    
    print(lengthOfLIS(ar))
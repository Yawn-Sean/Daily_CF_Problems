# Submission link: https://codeforces.com/gym/101798/submission/391331012
def main():
    n = II()
    nums = LII()
    
    nums.sort(reverse=True)
    
    k = n.bit_length() - 1
    
    ans = nums[0] * k
    pt = 1
    
    for i in range(k):
        for j in range(1 << i):
            ans += nums[pt + j] * (k - i - 2)
        pt += 1 << i
    
    print(ans)
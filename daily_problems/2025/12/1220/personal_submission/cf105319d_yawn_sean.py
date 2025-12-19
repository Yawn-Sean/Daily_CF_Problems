# Submission link: https://codeforces.com/gym/105319/submission/354059012
def main(): 
    n = II()
    nums = LII()
    
    l, r = 0, 0
    ans = 0
    
    c0 = [0] * 30
    c1 = [0] * 30
    
    while l < n:
        while r + 1 < n:
            v = (nums[r] ^ nums[r + 1]).bit_length() - 1
            if v >= 0:
                if nums[r] >> v & 1:
                    if c0[v]: break
                    c1[v] += 1
                else:
                    if c1[v]: break
                    c0[v] += 1
            r += 1
        
        ans += r - l + 1
        if l + 1 < n:
            v = (nums[l] ^ nums[l + 1]).bit_length() - 1
            if v >= 0:
                if nums[l] >> v & 1: c1[v] -= 1
                else: c0[v] -= 1
        l += 1
    
    print(ans)
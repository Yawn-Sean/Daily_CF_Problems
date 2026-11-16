# Submission link: https://codeforces.com/gym/106825/submission/398760917
def main():
    n = II()
    nums = LII()
    
    l, r = 0, 10 ** 9
    
    while l <= r:
        mid = (l + r) // 2
        
        flg = True
        
        soup = 0
        dumpling = 0
    
        for x in nums:
            if x < soup:
                w = fmin(soup // 2, (soup - x + 1) // 2)
                dumpling += w
                soup = fmin(mid, soup - x + mid - 2 * w)
            
            else:
                x -= soup
                
                if mid >= x:
                    soup = mid - x
                else:
                    soup = 0
                    if x - mid > dumpling:
                        flg = False
                        break
                    dumpling -= x - mid
        
        if flg: r = mid - 1
        else: l = mid + 1
    
    print(l)
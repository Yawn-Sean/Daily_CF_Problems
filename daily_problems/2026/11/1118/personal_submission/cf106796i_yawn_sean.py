# Submission link: https://codefores.com/gym/106796/submission/398917479
def main():
    n = II()
    nums = LII()
    
    cnt = [0] * 5
    
    for x in nums:
        cnt[x % 5] += 1
    
    orig = cnt[1] + 2 * cnt[2]
    c4 = cnt[4]
    
    res = -n * 5
    
    for i in range(cnt[4] // 3 + 1):
        w3 = cnt[3]
        w4 = cnt[4] - i * 3
        cur = i * 2
        
        w = fmin(w3, w4)
        w3 -= w
        w4 -= w
        cur += w * 2
        
        w = w3 // 2
        cur += w
        w3 -= w * 2
        
        cur -= w3 * 2 + w4
        
        res = fmax(res, cur)
    
    print(res + orig)
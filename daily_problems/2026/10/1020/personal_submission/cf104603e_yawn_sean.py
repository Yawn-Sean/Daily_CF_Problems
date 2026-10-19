# Submission link: https://codeforces.com/gym/104603/submission/395229788
def main():
    a, s, l, r = MII()
    
    ans = 0
    
    for diff in range(1, r - l + 1):
        for length in range(1, (r - l) // diff + 1):
            k = length + 1
            if s * 2 % k: continue
            
            v = s * 2 // k - length * diff
            if v % 2 == 0:
                vl = v // 2
                vr = vl + length * diff
                
                if vl >= l and vr <= r and vl <= a <= vr and (a - vl) % diff == 0:
                    ans += 1
    
    if s == a: ans += 1
    
    print(ans)
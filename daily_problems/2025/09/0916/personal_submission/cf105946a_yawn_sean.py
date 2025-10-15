# Submission link: https://codeforces.com/gym/105946/submission/338711524
def main():
    n = II()
    nums = LII()
    
    rnd = random.getrandbits(30)
    cnt = Counter(x + rnd for x in nums)
    
    c1 = cnt[1 + rnd]
    c2 = cnt[2 + rnd]
    c4 = cnt[4 + rnd]
    
    ans = c1 * (c1 - 1) * c2
    
    for x in cnt:
        v = x - rnd
        c = cnt[x]
        
        if v <= 2: continue
        
        if v == 3:
            ans += c1 * c2 * c * 2
        
        elif v == 4:
            ans += c2 * (c2 - 1) * c
            if x - 1 in cnt: ans += c1 * cnt[x - 1] * c * 2
        
        else:
            if x - 1 in cnt: ans += c1 * cnt[x - 1] * c * 2
            if x - 2 in cnt: ans += c2 * cnt[x - 2] * c * 2
            if v >= 7 and x - 4 in cnt: ans += c4 * cnt[x - 4] * c * 2
    
    print(ans)
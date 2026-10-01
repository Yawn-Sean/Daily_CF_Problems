# Submission link: https://codeforces.com/gym/106732/submission/392783613
def main():
    n, l, r = MII()
    nums = LII()
    r += 1
    
    mod = 998244353
    
    v1 = [0] * l
    v2 = [0] * r
    
    p1 = 0
    p2 = 0
    
    c1 = 0
    c2 = 0
    
    fen = FenwickTree(n + 1)
    fen.add(0, 1)
    
    for i in range(n):
        if nums[i] < l:
            if v1[nums[i]] == 0: c1 += 1
            v1[nums[i]] += 1
        
        if nums[i] < r:
            if v2[nums[i]] == 0: c2 += 1
            v2[nums[i]] += 1
        
        while p1 <= i and c1 == l:
            if nums[p1] < l:
                v1[nums[p1]] -= 1
                if v1[nums[p1]] == 0:
                    c1 -= 1
            p1 += 1
        
        while p2 <= i and c2 == r:
            if nums[p2] < r:
                v2[nums[p2]] -= 1
                if v2[nums[p2]] == 0:
                    c2 -= 1
            p2 += 1
        
        fen.add(i + 1, fen.rsum(p2, p1 - 1) % mod)
    
    print(fen.rsum(n, n))
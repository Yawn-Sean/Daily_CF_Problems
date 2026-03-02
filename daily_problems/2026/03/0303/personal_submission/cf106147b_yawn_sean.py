# Submission link: https://codeforces.com/gym/106147/submission/365079124
def main(): 
    def query(vals):
        print('?', len(vals), *vals, flush=True)
        return II()
    
    primes = [2, 3, 5, 7]
    saved_vals = []
    
    for p in primes:
        vals = [1]
        while vals[-1] * p <= 30000:
            vals.append(vals[-1] * p)
        saved_vals.append(query(vals))
    
    candidates = []
    for x in range(1, 30001):
        flg = True
        for i in range(4):
            v = x
            cur = 0
            while v:
                cur += v % primes[i]
                v //= primes[i]
            if cur != saved_vals[i]:
                flg = False
        if flg: candidates.append(x)
    
    l, r = 0, len(candidates) - 1
    while l <= r:
        mid = (l + r) // 2
        
        vals = [1]
        while vals[-1] * 2 <= candidates[mid]:
            vals.append(vals[-1] * 2)
        
        for i in range(mid, r + 1):
            if candidates[i] & -candidates[i] != candidates[i]:
                vals.append(candidates[i])
        
        if query(vals) == 1: l = mid + 1
        else: r = mid - 1
    
    print('!', candidates[r])
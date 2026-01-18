# Submission link: https://codeforces.com/gym/103483/submission/358465200
def main(): 
    n = II()
    v1 = LII()
    v2 = LII()
    
    acc1 = list(accumulate(v1, initial=0))
    acc2 = list(accumulate(v2, initial=0))
    
    l, r = 0, n
    while l <= r:
        mid = (l + r) // 2
        
        flg = True
        diff = 0
        for i in range(n):
            diff = fmin(acc1[i] - acc2[fmax(i - mid, 0)], diff)
            cur = acc2[fmin(i + mid + 1, n)] - acc1[i + 1]
            if cur + diff < 0:
                flg = False
        
        if flg: r = mid - 1
        else: l = mid + 1
    
    print(l if l < n else -1)
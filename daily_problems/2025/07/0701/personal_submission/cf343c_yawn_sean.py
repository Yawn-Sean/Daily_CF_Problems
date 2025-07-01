# Submission link: https://codeforces.com/contest/343/submission/326724675
def main():
    n, m = MII()
    heads = LII()
    reads = LII()

    l, r = 0, 10 ** 12

    while l <= r:
        mid = (l + r) // 2
        
        pt = 0
        
        for h in heads:
            if h <= reads[pt]:
                target = h + mid
            elif h - reads[pt] <= mid:
                target = fmax(h + (mid - (h - reads[pt])) // 2, h + mid - 2 * (h - reads[pt]))
            else:
                continue
            
            while pt < m and reads[pt] <= target:
                pt += 1
            
            if pt == m:
                break
        
        if pt < m: l = mid + 1
        else: r = mid - 1

    print(l)
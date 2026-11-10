# Submission link: https://codeforces.com/gym/106758/submission/398031754
def main():
    n, b = MII()
    nums = LII()
    
    k = 0
    base = [0] * b
    base_msk = [0] * b
    
    msks = []
    
    for x in nums:
        if x:
            flg = True
            msk = 0
            
            for i in range(b - 1, -1, -1):
                if x >> i & 1:
                    if base[i] == 0:
                        base[i] = x
                        base_msk[i] = (1 << k) ^ msk
                        flg = False
                        k += 1
                        break
                    else:
                        x ^= base[i]
                        msk ^= base_msk[i]
            
            if flg:
                msks.append(msk)
    
    c0 = -1
    c1 = -1
    c2 = -1
    
    for i in range(k):
        total_msk = (1 << i) - 1
        total_nmsk = (1 << i) - 1
        c = 0
        
        for v in msks:
            if v >> i & 1:
                c += 1
                total_msk &= v
            else:
                total_nmsk &= ~v
        
        same = (total_msk & total_nmsk).bit_count() + 1
        
        if c == 0: c0 = fmax(c0, same)
        elif c == 1: c1 = fmax(c1, same)
        else: c2 = fmax(c2, same)
    
    for extra in range(8):
        if (1 << extra) - extra - 1 >= c0 and (1 << extra) - 1 >= c1 and 1 << extra >= c2:
            print(extra)
            break
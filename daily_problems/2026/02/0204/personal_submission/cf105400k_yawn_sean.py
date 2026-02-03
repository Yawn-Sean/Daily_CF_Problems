# Submission link: https://codeforces.com/gym/105400/submission/361252905
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        st_range = sorted(range(n), key=lambda x: nums[x])
        fen = FenwickTree(n)
        
        res = [0] * n
        for i in range(n - 1, -1, -1):
            res[i] = fen.rsum(0, st_range[i])
            fen.add(st_range[i], 1)
        
        for i in range(1, n):
            res[i] += res[i - 1]
        
        flg = True
        for i in range(n):
            if nums[st_range[i]] < res[i]:
                flg = False
        
        outs.append('YES' if flg else 'NO')
    
    print('\n'.join(outs))
# Submission link: https://codeforces.com/gym/106259/submission/366906292
def main(): 
    M = 5 * 10 ** 5
    mod = 998244353
    
    f = [0] * (M + 1)
    
    f[0] = 1
    for i in range(1, M + 1):
        f[i] = i * f[i - 1] % mod
    
    cnt = [2] * (M + 1)
    cnt[1] = 0
    cnt[2] = 0
    cnt[10] = 3
    cnt[11] = 3
    cnt[12] = 3
    
    for i in range(9, 2, -1):
        cnt[i] = cnt[f[i]] + 1
    
    t = II()
    outs = []
    
    for _ in range(t):
        n, q = MII()
        nums = LII()
        
        tmp = nums[:]
        op_cnt = [cnt[x] for x in nums]
        
        fen = FenwickTreeArray(nums)
        seg = SegTree(fmax, 0, op_cnt)
        
        for _ in range(q):
            o, l, r = MII()
            if o == 1:
                l -= 1
                while True:
                    p = seg.max_right(l, lambda x: x == 0)
                    if p >= r: break
                    
                    op_cnt[p] -= 1
                    if op_cnt[p] == 0:
                        if tmp[p]:
                            fen.add(p, -nums[p])
                            nums[p] = 0
                    
                    elif op_cnt[p] == 1:
                        if tmp[p] == 10:
                            fen.add(p, 818355289)
                            nums[p] = 821984089
                        elif tmp[p] == 11:
                            fen.add(p, 604139442)
                            nums[p] = 644056242
                        elif tmp[p] == 12:
                            fen.add(p, 48654759)
                            nums[p] = 527656359
                        else:
                            fen.add(p, f[nums[p]] - nums[p])
                            nums[p] = f[nums[p]]
                    
                    else:
                        fen.add(p, f[nums[p]] - nums[p])
                        nums[p] = f[nums[p]]
                    
                    seg.set(p, seg.get(p) - 1)
                    l = p + 1
            else:
                outs.append(fen.rsum(l - 1, r - 1) % mod)
    
    print('\n'.join(map(str, outs)))
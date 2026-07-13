# Submission link: https://codeforces.com/gym/103306/submission/382351814
def main():
    n, m = MII()
    p = LII()
    ts = LII()
    
    M = 2 * 10 ** 5 + 5
    
    updates = [set() for _ in range(M)]
    next_update = [0] * n
    
    rnd = random.getrandbits(30)
    
    cur_status = [0] * n
    
    for i in range(n):
        cur = i % (2 * p[i])
        
        if cur < p[i]:
            cur_status[i] = 1
            next_update[i] = p[i] - cur
            updates[p[i] - cur].add(i ^ rnd)
        
        else:
            cur_status[i] = 0
            next_update[i] = 2 * p[i] - cur
            updates[2 * p[i] - cur].add(i ^ rnd)
    
    seg = SegTree(fmax, 0, cur_status)
    
    ans = [0] * m
    
    st_range = sorted(range(m), key=lambda x: ts[x])
    pt = 0
    
    for i in range(10 ** 5 + 5):
        for msk in updates[i]:
            idx = msk ^ rnd
            seg.set(idx, seg.get(idx) ^ 1)
    
            next_update[idx] = i + p[idx]
            updates[i + p[idx]].add(idx ^ rnd)
        
        updates[i].clear()
        
        if pt < m and ts[st_range[pt]] == i:
            if seg.all_prod() == 0: ans[st_range[pt]] = -1
            else:
                idx = seg.max_right(0, lambda x: x == 0)
                ans[st_range[pt]] = idx
                
                seg.set(idx, seg.get(idx) ^ 1)
    
                updates[next_update[idx]].remove(idx ^ rnd)
                next_update[idx] = i + p[idx] + 1
                updates[i + p[idx] + 1].add(idx ^ rnd)
            pt += 1
    
    print('\n'.join(f'{ans[i]} {ts[i] + ans[i]}' if ans[i] >= 0 else '-1 -1' for i in range(m)))
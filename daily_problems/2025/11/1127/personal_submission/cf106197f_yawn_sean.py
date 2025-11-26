# Submission link: https://codeforces.com/gym/106197/submission/350724882
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = [0] + LII()
    
        pos = [0] * (n + 1)
        
        for i in range(n + 1):
            pos[nums[i]] = i
        
        ops = []
        
        def operate(vals):
            vis_idx = [0] * (n + 1)
            vis_val = [0] * (n + 1)
            
            for x in vals:
                vis_val[x] = 1
                vis_idx[pos[x]] = 1
            
            idxs = [i for i in range(n + 1) if vis_idx[i]]
            vals = [i for i in range(n + 1) if vis_val[i]]
            
            for idx, val in zip(idxs, vals):
                nums[idx] = val
                pos[val] = idx
            
            ops.append(f"{len(idxs)} {' '.join(map(str, idxs))}")
        
        val = 1 << n.bit_length() - 1
        def move():
            if nums[n] == n: return
            
            vals = [nums[n], n]
            cur = nums[n] ^ n
            
            while cur:
                vals.append(cur & -cur)
                cur -= cur & -cur
            
            operate(vals)
        
        if n & -n == n:
            if nums[n] != n:
                outs.append('-1')
                continue
            elif n % 4 == 0:
                operate(list(range(1, n)))
        
        elif n % 4 == 3:
            operate(list(range(1, n + 1)))
        
        elif n % 4 == 1:
            operate(list(range(1, n - 1)))
            operate(list(range(2, n + 1)))
            operate(list(range(1, n - 1)))
        
        elif n % 4 == 0:
            operate(list(range(1, val)))
            move()
            operate(list(range(1, n)))
        
        else:
            operate(list(range(1, val)))
            move()
            operate(list(range(1, n - 2)))
            operate(list(range(2, n)))
            operate(list(range(1, n - 2)))
        
        outs.append(str(len(ops)))
        outs.append('\n'.join(ops))
    
    print('\n'.join(outs))
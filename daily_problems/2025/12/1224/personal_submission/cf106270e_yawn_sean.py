# Submission link: https://codeforces.com/gym/106270/submission/354647633
def main(): 
    rnd = random.getrandbits(30)
    
    n, q = MII()
    nums = [x + rnd for x in LII()]
    
    mod = 10 ** 9 + 7
    
    cur_ma = 0
    step = 1
    
    pref_steps = [0] * n
    pos = defaultdict(list)
    
    for i in range(n):
        pref_steps[i] = step
        if nums[i] > cur_ma:
            cur_ma = nums[i]
            step = 0
        step += 1
    
        pos[nums[i]].append(i)
    
    pref_max = nums[:]
    
    for i in range(1, n):
        pref_steps[i] = fmax(pref_steps[i - 1], pref_steps[i])
        pref_max[i] = fmax(pref_max[i - 1], pref_max[i])
    
    rev2_pows = [0] * (n + 1)
    rev2_pows[0] = 1
    rev2 = (mod + 1) // 2
    
    for i in range(n):
        rev2_pows[i + 1] = rev2_pows[i] * rev2 % mod
    
    def solve(idx, k):
        last_pos = fmin(pos[nums[idx]][0] + k, n - 1)
        if pref_max[last_pos] > nums[idx]: return 0
        if pref_steps[last_pos] > k: return 0
        if last_pos < idx: return 0
        ans = 1 if pos[nums[idx]][0] == idx else rev2
        ans = ans * rev2_pows[bisect.bisect_right(pos[nums[idx]], last_pos) - bisect.bisect_right(pos[nums[idx]], idx)] % mod
        
        return ans
    
    outs = []
    for _ in range(q):
        query = LII()
        
        if query[0] == 1:
            idx = query[1] - 1
            k = query[2]
            outs.append(f'{solve(idx, k)}')
        else:
            idx = query[1] - 1
            k = pref_steps[idx]
            outs.append(f'{k} {solve(idx, k)}')
    
    print('\n'.join(outs))
# Submission link: https://codeforces.com/gym/106290/submission/355974473
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        first_pos = [-1] * (n + 1)
        last_pos = [-1] * (n + 1)
        prev = [0] * n
        
        for i in range(n):
            prev[i] = last_pos[nums[i]]
            last_pos[nums[i]] = i
            if first_pos[nums[i]] == -1:
                first_pos[nums[i]] = i
        
        ans = 0
        seg = LazySegTree(fmax, 0, add, add, 0, n)
        
        for i in range(n + 1):
            if last_pos[i] != -1:
                ans += 1
        
        to_add = 0
        
        for i in range(n):
            if last_pos[nums[i]] != i:
                seg.apply(prev[i] + 1, i + 1, 1)
            elif prev[i] != -1:
                seg.apply(0, prev[i] + 1, -1)
                seg.apply(first_pos[nums[i]] + 1, last_pos[nums[i]] + 1, 1)
            to_add = fmax(to_add, seg.all_prod())
        
        outs.append(ans + to_add)
    
    print('\n'.join(map(str, outs)))
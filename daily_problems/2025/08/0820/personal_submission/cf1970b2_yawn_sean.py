# Submission link: https://codeforces.com/contest/1970/submission/334536640
def main():
    n = II()
    nums = LII()
    st_range = sorted(range(1, n), key=lambda x: -nums[x])
    
    xs = [1] * n
    ys = [1] * n
    
    target = [0] * n
    
    last_idx = 0
    for i in range(n - 1):
        idx = st_range[i]
        nums[idx] -= 1
        
        xs[idx] = xs[last_idx] + 1
        if 1 <= ys[last_idx] + nums[idx] <= n:
            ys[idx] = ys[last_idx] + nums[idx]
        else:
            ys[idx] = ys[last_idx] - nums[idx]
        
        if nums[idx] < 0: target[idx] = idx
        else: target[idx] = last_idx
        
        last_idx = idx
    
    print('YES')
    print('\n'.join(f'{xs[i]} {ys[i]}' for i in range(n)))
    print('\n'.join(str(x + 1) for x in target))
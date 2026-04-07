# Submission link: https://codeforces.com/gym/106463/submission/370070663
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n, k, x, y = MII()
        nums = LII()
        
        for i in range(1, k):
            nums[i] = (nums[i] + nums[i - 1]) % n
        
        vis = [-1] * n
        target = [0] * k
        
        for i in range(k - 1, -1, -1):
            to_find_pos = (nums[i] + (x - y)) % n
            target[i] = target[vis[to_find_pos]] if vis[to_find_pos] != -1 else (y + nums[-1] - nums[i]) % n
            vis[nums[i]] = i
        
        ans = []
        for i in range(n):
            if i != x:
                to_find_pos = (x - i) % n
                ans.append(target[vis[to_find_pos]] if vis[to_find_pos] != -1 else (i + nums[-1]) % n)
        
        outs.append(' '.join(map(str, ans)))
    
    print('\n'.join(outs))
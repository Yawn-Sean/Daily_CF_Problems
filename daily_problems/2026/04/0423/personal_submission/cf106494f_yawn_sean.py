# Submission link: https://codeforces.com/gym/106494/submission/372104559
def main():
    n, q = MII()
    nums = LII()
    
    mod = 998244353
    rev2 = (mod + 1) // 2
    
    M = 2200000
    seg_tree = [0] * M
    dp = [1] * M
    
    ls = [-1] * M
    rs = [-1] * M
    pos = [0] * n
    
    ls[1] = 0
    rs[1] = n - 1
    
    for i in range(1, M):
        if rs[i] > ls[i]:
            mid = (ls[i] + rs[i]) // 2
            ls[2 * i] = ls[i]
            rs[2 * i] = mid
            ls[2 * i + 1] = mid + 1
            rs[2 * i + 1] = rs[i]
        elif ls[i] >= 0:
            pos[ls[i]] = i
    
    for i in range(M - 1, -1, -1):
        if ls[i] < rs[i]:
            mid = (ls[i] + rs[i]) // 2
            seg_tree[i] = seg_tree[2 * i] + seg_tree[2 * i + 1] + (nums[mid] > nums[mid + 1])
            if seg_tree[i] == 0: dp[i] = rs[i] - ls[i] + 1
            else: dp[i] = (dp[2 * i] + dp[2 * i + 1]) * rev2 % mod
    
    outs = []
    for _ in range(q):
        idx, val = MII()
        idx -= 1
        
        nums[idx] = val
        p = pos[idx] // 2
        
        while p:
            mid = (ls[p] + rs[p]) // 2
            seg_tree[p] = seg_tree[2 * p] + seg_tree[2 * p + 1] + (nums[mid] > nums[mid + 1])
            if seg_tree[p] == 0: dp[p] = rs[p] - ls[p] + 1
            else: dp[p] = (dp[2 * p] + dp[2 * p + 1]) * rev2 % mod
            p //= 2
        
        outs.append(dp[1])
    
    print('\n'.join(map(str, outs)))
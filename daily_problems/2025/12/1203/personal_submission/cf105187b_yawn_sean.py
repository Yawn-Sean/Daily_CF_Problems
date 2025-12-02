# Submission link: https://codeforces.com/gym/105187/submission/351562638
def main(): 
    n = II()
    nums = LII()
    xs = []
    ys = []
    
    for _ in range(n):
        x, y = MII()
        xs.append(x)
        ys.append(y)
    
    M = 5 * 10 ** 5 + 100
    fen = FenwickTree(M)
    
    for i in range(n):
        x, y = nums[xs[i]], nums[ys[i]]
        
        if x > y:
            x, y = y, x
        
        fen.add(x, 1)
        fen.add(fmin(fmax(x + 1, y + 1), fmax(x + 3, y)), 1)
    
    ans = [0] * (2 * n)
    
    for i in range(n):
        x, y = nums[xs[i]], nums[ys[i]]
        
        if x > y:
            x, y = y, x
        
        fen.add(x, -1)
        fen.add(fmin(fmax(x + 1, y + 1), fmax(x + 3, y)), -1)
        
        ans[xs[i]] = 2 * n - fen.rsum(0, nums[xs[i]] + 3)
        ans[ys[i]] = 2 * n - fen.rsum(0, nums[ys[i]] + 3)
        
        if nums[xs[i]] + 3 >= nums[ys[i]]: ans[xs[i]] -= 1
        if nums[ys[i]] + 3 >= nums[xs[i]]: ans[ys[i]] -= 1
        
        fen.add(x, 1)
        fen.add(fmin(fmax(x + 1, y + 1), fmax(x + 3, y)), 1)
    
    print(' '.join(map(str, ans)))
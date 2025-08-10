# Submission link: https://codeforces.com/contest/652/submission/333221731
def main():
    n, q = MII()
    nums = LII()
    
    tmp = [[] for _ in range(n + 1)]
    
    for _ in range(q):
        x, y = MII()
        tmp[x].append(y)
        tmp[y].append(x)
    
    vis = [0] * (n + 1)
    
    l = 0
    ans = 0
    
    for r in range(n):
        vis[nums[r]] = 1
        
        cnt = 0
        for x in tmp[nums[r]]:
            cnt += vis[x]
        
        while cnt:
            for x in tmp[nums[l]]:
                if x == nums[r]:
                    cnt -= 1
            vis[nums[l]] = 0
            l += 1
        
        ans += r - l + 1
    
    print(ans)
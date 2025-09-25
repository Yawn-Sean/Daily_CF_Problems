# Submission link: https://codeforces.com/gym/106043/submission/340356942
def main():
    n = II()
    nums = LII()
    dsu = UnionFind(n)
    vis = [0] * n
    
    max_length = [0] * (n + 1)
    
    for i in sorted(range(n), key=lambda x: nums[x]):
        if i and vis[i - 1]: dsu.merge(i, i - 1)
        if i + 1 < n and vis[i + 1]: dsu.merge(i, i + 1)
        
        vis[i] = 1
        if nums[i] < n:
            max_length[nums[i]] = fmax(max_length[nums[i]], dsu.getSize(i))
    
    for i in range(1, n + 1):
        max_length[i] = fmin(max_length[i], max_length[i - 1])
    
    ans = [0] * (n + 1)
    
    for i in range(n + 1):
        ans[max_length[i]] = i + 1
    
    for i in range(n - 1, -1, -1):
        ans[i] = fmax(ans[i], ans[i + 1])
    
    print(' '.join(map(str, ans[1:])))
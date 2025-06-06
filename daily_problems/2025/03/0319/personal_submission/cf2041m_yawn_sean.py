# Submission link: https://codeforces.com/contest/2041/submission/311338033
def main():
    def solve(x):
        target = sorted(x)
        
        ans = n * n
        pq = []
        r = 0
        
        for l in range(n):
            while r < l and pq and pq[0] == target[r]:
                heappop(pq)
                r += 1
            
            while r >= l and r < n and x[r] == target[r]:
                r += 1
            
            ans = fmin(ans, l * l + (n - r) * (n - r))
            
            if r <= l:
                heappush(pq, x[l])
        
        return ans

    n = II()
    nums = LII()

    ans = solve(nums)

    nums.reverse()
    for i in range(n):
        nums[i] = -nums[i]

    print(fmin(ans, solve(nums)))
# Submission link: https://codeforces.com/contest/207/submission/330522409
def main():
    n = II()
    
    nums = [II() for _ in range(n)]
    nums += nums
    
    for i in range(2 * n):
        nums[i] = fmax(0, i - nums[i])
    
    st = SparseTable([nums[i] * (2 * n) + i for i in range(2 * n)], fmin)
    
    nth_step = [[0] * (2 * n) for _ in range(20)]
    
    for i in range(2 * n):
        nth_step[0][i] = st.query(nums[i], i) % (2 * n)
    
    for i in range(19):
        for j in range(2 * n):
            nth_step[i + 1][j] = nth_step[i][nth_step[i][j]]
    
    ans = 0
    
    for i in range(n, 2 * n):
        if i - nums[i] >= n - 1:
            ans += 1
            continue
        
        cur = i
        for j in range(19, -1, -1):
            if i - nums[nth_step[j][cur]] < n - 1:
                ans += 1 << j
                cur = nth_step[j][cur]
        ans += 2
    
    print(ans)
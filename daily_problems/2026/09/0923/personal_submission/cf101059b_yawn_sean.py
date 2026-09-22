# Submission link: https://codeforces.com/gym/101059/submission/391586437
def main():
    n = II()
    nums = LII()
    
    M = 10 ** 5 + 5
    
    first_pos = [-1] * M
    last_pos = [-1] * M
    
    res = [0] * M
    
    for i in range(n):
        if first_pos[nums[i]] == -1:
            first_pos[nums[i]] = i
        else:
            res[nums[i]] = fmax(res[nums[i]], i - last_pos[nums[i]] - 1)
        last_pos[nums[i]] = i
    
    ans = n
    
    for i in range(M):
        if first_pos[i] != -1:
            res[i] = fmax(res[i], first_pos[i] + n - 1 - last_pos[i])
            ans = fmin(ans, res[i])
    
    print(ans + n)
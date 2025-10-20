# Submission link: https://codeforces.com/gym/105335/submission/344800259
def main(): 
    n = II()
    nums = LII()
    
    tmp = [nums[0] - 1, nums[1] - 1]
    if tmp[1] > tmp[0]:
        tmp[1] -= 1
    
    tmp[1] += n * (n - 1) // 2
    
    tmp[0] += tmp[1] // (n - 1)
    tmp[1] %= n - 1
    tmp[0] %= n
    
    ans = [tmp[0] + 1, tmp[1] + 1]
    if ans[1] >= ans[0]: ans[1] += 1
    
    vis1 = [0] * (n + 1)
    vis2 = [1] * (n + 1)
    
    for i in range(2, n):
        vis1[nums[i]] = 1
    
    for x in ans:
        vis2[x] = 0
    
    mapping = [0] * (n + 1)
    p1, p2 = 1, 1
    
    for _ in range(n - 2):
        while not vis1[p1]: p1 += 1
        while not vis2[p2]: p2 += 1
        mapping[p1] = p2
        p1 += 1
        p2 += 1
    
    for i in range(2, n):
        ans.append(mapping[nums[i]])
    
    print(' '.join(map(str, ans)))
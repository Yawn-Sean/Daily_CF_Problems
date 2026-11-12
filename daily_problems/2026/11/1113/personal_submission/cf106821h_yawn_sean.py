# Submission link: https://codeforces.com/gym/106821/submission/398229257
def main():
    n = II()
    nums = LII()
    
    cnt = [0] * (n + 1)
    
    for x in nums:
        if x < n:
            cnt[x] += 1
    
    mex = 0
    
    while cnt[mex]:
        mex += 1
    
    if mex and (n % 2 or min(cnt[:mex]) == 1): print('Dinny')
    else: print('Tie')
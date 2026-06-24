# Submission link: https://codeforces.com/gym/106020/submission/379985872
def main():
    n = II()
    nums = LII()
    
    ans = 0
    idxs = [i for i in range(n) if nums[i]]
    
    for i in range(1, len(idxs)):
        x = idxs[i - 1]
        y = idxs[i]
        if fmin(nums[x], nums[y]) == 1 and fmax(nums[x], nums[y]) <= 2:
            lx = idxs[i - 2] if i - 2 >= 0 else -1
            ry = idxs[i + 1] if i + 1 < len(idxs) else n
            
            ans += (x - lx) * (ry - y)
            if y - x == 1: ans -= 1
    
    print(ans)
# Submission link: https://codeforces.com/gym/106795/submission/396639978
def main(): 
    prs = []
    
    for i in range(2, 51):
        for j in range(2, i):
            if i % j == 0: break
        else:
            prs.append(i)
    
    k = len(prs)
    
    tag = [0] * 2501
    big = [0] * 2501
    
    for i in range(1, 2501):
        msk = 0
        cur = i
        
        for j in range(k):
            while cur % prs[j] == 0:
                msk |= 1 << j
                cur //= prs[j]
        
        tag[i] = msk
        if cur >= 50: big[i] = cur
    
    vis = [0] * 2501
    
    n = II()
    nums = LII()
    
    res = [0] * n
    
    ans = n
    
    for i in range(1 << k):
        cur = i.bit_count()
        for j in range(n):
            res[j] = 1 if tag[nums[j]] & i == 0 else 0
        
        flg = True
        
        for j in range(n):
            if res[j]:
                if big[nums[j]] == 0: flg = False
                else:
                    if vis[big[nums[j]]] == 0:
                        vis[big[nums[j]]] = 1
                        cur += 1
        
        if flg:
            ans = fmin(ans, cur)
        
        for j in range(n):
            vis[big[nums[j]]] = 0
    
    print(ans)
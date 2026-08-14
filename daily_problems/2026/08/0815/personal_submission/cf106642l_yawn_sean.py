# Submission link: https://codeforces.com/gym/106642/submission/387002236
def main():
    n = II()
    nums = LII()
    
    special = 0
    vis = [0] * (n + 1)
    stk = []
    
    for x in nums:
        if stk and stk[-1] == x:
            vis[x] = 0
            stk.pop()
        else:
            if vis[x]:
                special = x
                break
            
            vis[x] = 1
            stk.append(x)
    
    if special == 0:
        print(n)
        print(' '.join(map(str, range(1, n + 1))))
    else:
        l = -1
        r = -1
        
        for i in range(2 * n):
            if nums[i] == special:
                if l == -1: l = i
                r = i
        
        vis = [0] * (n + 1)
        
        for i in range(l + 1, r):
            vis[nums[i]] ^= 1
        
        def check(x):
            stk = []
            for v in nums:
                if v != x:
                    if stk and stk[-1] == v:
                        stk.pop()
                    else: stk.append(v)
            return len(stk) == 0
        
        ans = []
        
        if check(special):
            ans.append(special)
        
        v = vis.index(1)
        if check(v): ans.append(v)
        
        ans.sort()
        print(len(ans))
        if ans: print(*ans)
# Submission link: https://codeforces.com/gym/105129/submission/344618256
def main(): 
    t = II()
    outs = []
    
    prs = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]
    
    to_check = [1]
    for x in prs:
        for i in range(len(to_check)):
            to_check.append(to_check[i] * x)
    
    to_check.sort()
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        vis = [0] * 51
        for x in nums:
            vis[x] = 1
        
        for v in to_check:
            for i in range(51):
                if vis[i] and math.gcd(i, v) == 1:
                    break
            else:
                outs.append(v)
                break
    
    print('\n'.join(map(str, outs)))

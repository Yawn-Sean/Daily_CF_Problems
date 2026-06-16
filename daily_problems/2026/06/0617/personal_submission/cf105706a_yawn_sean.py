# Submission link: https://codeforces.com/gym/105706/submission/379066335
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, q = MII()
        nums = LII()
        
        next_pos1 = [n] * n
        next_pos = [[n] * (n + 1) for _ in range(20)]
        
        pos = [n] * (n + 2)
        
        for i in range(n - 1, -1, -1):
            next_pos[0][i] = pos[nums[i] + 1]
            pos[nums[i]] = i
            next_pos1[i] = pos[1]
        
        for i in range(19):
            for j in range(n):
                next_pos[i + 1][j] = next_pos[i][next_pos[i][j]]
    
        ans = []
        for _ in range(q):
            l, r = GMI()
            
            if next_pos1[l] > r: ans.append(1)
            else:
                l = next_pos1[l]
                res = 2
                
                for i in range(19, -1, -1):
                    if next_pos[i][l] <= r:
                        l = next_pos[i][l]
                        res += 1 << i
                
                ans.append(res)
        
        outs.append(' '.join(map(str, ans)))
    
    print('\n'.join(outs))
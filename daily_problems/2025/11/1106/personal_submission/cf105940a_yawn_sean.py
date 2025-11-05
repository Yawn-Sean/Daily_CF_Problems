# Submission link: https://codeforces.com/gym/105940/submission/347364057
def main(): 
    t = II()
    mod = 10 ** 9 + 7
    
    outs = []
    
    def f(i, j, k, cur_mod):
        return ((i * 3 + j) * 3 + k) * 3 + cur_mod
    
    method = [4, 3, 3]
    
    for _ in range(t):
        n = II()
        dp = [0] * 81
        
        for i in range(1, 10):
            x, y, z = 1, 0, 0
            
            if i % 3 == 0: x += 1
            elif i % 3 == 1: y += 1
            else: z += 1
            
            dp[f(x, y, z, i % 3)] += 1
    
        for _ in range(n - 1):
            ndp = [0] * 81
            
            for x in range(3):
                for y in range(3):
                    for z in range(3):
                        for cur_mod in range(3):
                            if dp[f(x, y, z, cur_mod)]:
                                nstatus = [x, y, z]
                                
                                for choice in range(3):
                                    ncur_mod = (cur_mod + choice) % 3
                                    
                                    nstatus[ncur_mod] += 1
                                    nstatus[ncur_mod] %= 3
                                    
                                    nx, ny, nz = nstatus
                                    ndp[f(nx, ny, nz, ncur_mod)] += dp[f(x, y, z, cur_mod)] * method[choice]
                                    ndp[f(nx, ny, nz, ncur_mod)] %= mod
                                    
                                    nstatus[ncur_mod] -= 1
                                    nstatus[ncur_mod] %= 3
            
            dp = ndp
        
        ans = 0
        
        for x in range(3):
            for y in range(3):
                for z in range(3):
                    if (x * (x - 1) // 2 + y * (y - 1) // 2 + z * (z - 1) // 2) % 3 == 0:
                        for cur_mod in range(3):
                            ans += dp[f(x, y, z, cur_mod)]
                            ans %= mod
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))
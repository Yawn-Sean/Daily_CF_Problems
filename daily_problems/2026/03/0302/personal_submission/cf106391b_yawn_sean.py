# Submission link: https://codeforces.com/gym/106391/submission/364965839
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
        used = [0] * n
        
        outs.append('YES')
        ops = []
        
        for i in range(n - 1, 0, -1):
            vis = [-1] * i
            
            for j in range(n):
                if not used[j]:
                    x = nums[j] % i
                    if vis[x] != -1:
                        used[j] = 1
                        ops.append(f'{vis[x] + 1} {j + 1}')
                        break
                    vis[x] = j
        
        outs.append('1')
        ops.reverse()
        outs.append('\n'.join(ops))
    
    print('\n'.join(outs))
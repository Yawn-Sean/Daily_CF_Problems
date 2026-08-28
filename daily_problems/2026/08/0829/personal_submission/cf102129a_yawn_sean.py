# Submission link: https://codeforces.com/gym/102129/submission/388639735
def main():
    k = II()
    v1 = LII()
    v2 = LII()
    
    def solve(x1, x2):
        cur_len = len(x1)
        
        if cur_len == 1:
            return [x1[0] * x2[0]]
        
        ncur_len = cur_len // 3
        
        ans = [0] * cur_len
        
        w1 = [0] * ncur_len
        w2 = [0] * ncur_len
        
        for i in range(ncur_len):
            w1[i] = x1[ncur_len + i] + x1[2 * ncur_len + i]
            w2[i] = x2[ncur_len + i] + x2[2 * ncur_len + i]
    
        res = solve(w1, w2)
        
        for i in range(ncur_len):
            ans[i] += res[i]
        
        for i in range(ncur_len):
            w1[i] = x1[i]
            w2[i] = x2[i] + x2[2 * ncur_len + i]
        
        res = solve(w1, w2)
        
        for i in range(ncur_len):
            ans[ncur_len + i] += res[i]
        
        for i in range(ncur_len):
            w1[i] = x1[2 * ncur_len + i]
            w2[i] = x2[i]
        
        res = solve(w1, w2)
        
        for i in range(ncur_len):
            ans[ncur_len + i] += res[i]
        
        for i in range(ncur_len):
            w1[i] = x1[i] + x1[ncur_len + i] + x1[2 * ncur_len + i]
            w2[i] = x2[i] + x2[ncur_len + i] + x2[2 * ncur_len + i]
        
        res = solve(w1, w2)
        
        for i in range(ncur_len):
            ans[2 * ncur_len + i] = res[i] - ans[i] - ans[ncur_len + i]
        
        return ans
    
    print(' '.join(map(str, solve(v1, v2))))
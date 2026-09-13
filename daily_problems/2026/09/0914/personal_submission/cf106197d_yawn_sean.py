# Submission link: https://codeforces.com/gym/106197/submission/390542241
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, k = MII()
        nums = [1 if c == '+' else -1 for c in I()]
        
        ans = []
        
        for i in range(n):
            if k % 2: k -= nums[i]; ans.append('#')
            else: ans.append('.')
            k //= 2
        
        outs.append(''.join(ans) if k == 0 else '-1')
    
    print('\n'.join(outs))
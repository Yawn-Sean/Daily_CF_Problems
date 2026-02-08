# Submission link: https://codeforces.com/gym/103451/submission/362017966
def main(): 
    n = II()
    and_val = [int(c) for c in I()]
    or_val = [int(c) for c in I()]
    xor_val = [int(c) for c in I()]
    
    k = len(and_val)
    
    ans = 1
    mod = 10 ** 9 + 7
    
    saved = pow(2, n - 1, mod)
    
    for i in range(k):
        res = 0
        
        if and_val[i]:
            if or_val[i] and n % 2 == xor_val[i]:
                res = 1
        else:
            if or_val[i] == 0:
                if xor_val[i] == 0:
                    res = 1
            else:
                if n >= 2:
                    res = saved
                    if xor_val[i] == 0:
                        res -= 1
                        res %= mod
                    if n % 2 == xor_val[i]:
                        res -= 1
                        res %= mod
        
        ans = ans * res % mod
    
    print(ans)
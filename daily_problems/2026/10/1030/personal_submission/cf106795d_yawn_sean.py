# Submission link: https://codeforces.com/gym/106795/submission/396522312
def main(): 
    n = II()
    s = I()
    
    if all(s[i] != s[i - 1] for i in range(1, n)): print(n)
    else:
        cur = 0
        
        for x in s:
            if x == 'G': cur += 1
            else: cur += 2
            cur %= 3
        
        print(1 if cur else 2)
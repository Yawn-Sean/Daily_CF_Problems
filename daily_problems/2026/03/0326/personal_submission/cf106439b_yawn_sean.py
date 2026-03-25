# Submission link: https://codeforces.com/gym/106439/submission/368133472
def main(): 
    t = II()
    outs = []
    
    saved = [1, 3, 5, 2, 4]
    
    for _ in range(t):
        n = II()
        
        if n == 2 or n == 3: outs.append('-1')
        else:
            ans = []
            
            for x in range(n // 5):
                for i in range(5):
                    ans.append(x * 5 + saved[i])
            
            if n % 5 == 1:
                ans.append(n)
            elif n % 5 == 2:
                ans[-1] = n
                ans.append(n - 3)
                ans.append(n - 1)
            elif n % 5 == 3:
                ans[-1] = n - 1
                ans.append(n - 4)
                ans.append(n - 2)
                ans.append(n)
            elif n % 5 == 4:
                ans.append(n - 2)
                ans.append(n)
                ans.append(n - 3)
                ans.append(n - 1)
            
            outs.append(' '.join(map(str, ans)))
    
    print('\n'.join(outs))
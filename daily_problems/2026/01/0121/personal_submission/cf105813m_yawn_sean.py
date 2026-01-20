# Submission link: https://codeforces.com/gym/105813/submission/358868465
def main(): 
    t = II()
    outs = []
    
    digits = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
    
    for _ in range(t):
        s = [int(c) for c in I()]
        ans = []
        
        for c in s:
            for _ in range(2):
                for x in digits:
                    if x != c:
                        ans.append(x)
            ans.append(c)
        
        ans.pop()
        outs.append(''.join(map(str, ans)))
    
    print('\n'.join(outs))
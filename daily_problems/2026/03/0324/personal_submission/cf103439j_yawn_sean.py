# Submission link: https://codeforces.com/gym/103439/submission/367893759
def main(): 
    n = II()
    s = I()
    
    ca = s.count('A')
    cb = s.count('B')
    cc = s.count('C')
    
    if ca == n and cb == n and cc == n: print(0)
    else:
        l = 0
        r = 0
        
        while l < 3 * n:
            while max(ca, cb, cc) > n and r < 3 * n:
                if s[r] == 'A': ca -= 1
                elif s[r] == 'B': cb -= 1
                else: cc -= 1
                r += 1
            
            if max(ca, cb, cc) > n: break
            
            if ca == n and cb == n:
                print(1)
                print(l + 1, r, 'C')
                exit()
            
            if ca == n and cc == n:
                print(1)
                print(l + 1, r, 'B')
                exit()
            
            if cb == n and cc == n:
                print(1)
                print(l + 1, r, 'A')
                exit()
            
            if s[l] == 'A': ca += 1
            elif s[l] == 'B': cb += 1
            else: cc += 1
            l += 1
        
        ca = 0
        cb = 0
        cc = 0
        
        print(2)
        for i in range(3 * n):
            if s[i] == 'A': ca += 1
            elif s[i] == 'B': cb += 1
            else: cc += 1
            
            if ca == n:
                print(i + 2, 3 * n, 'B')
                print(3 * n - (n - cc) + 1, 3 * n, 'C')
                break
            
            if cb == n:
                print(i + 2, 3 * n, 'A')
                print(3 * n - (n - cc) + 1, 3 * n, 'C')
                break
            
            if cc == n:
                print(i + 2, 3 * n, 'A')
                print(3 * n - (n - cb) + 1, 3 * n, 'B')
                break
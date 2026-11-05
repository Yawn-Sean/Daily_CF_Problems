# Submission link: https://codeforces.com/gym/106806/submission/397428986
def main(): 
    s = I()
    n = len(s)
    
    if min(s) == max(s):
        print(n)
        print(' '.join(s))
    else:
        for i in range(2, n):
            if n % i == 0:
                flg = True
                for j in range(n):
                    if s[j] != s[j % i]:
                        flg = False
                        break
                
                if flg:
                    print(2)
                    print(s[:i + 1], s[i + 1:])
                    exit()
        
        print(1)
        print(s)
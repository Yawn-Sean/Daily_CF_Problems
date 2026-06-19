# Submission link: https://codeforces.com/gym/104395/submission/379492427
def main():
    n, k = MII()
    s = I()
    
    ans = 'a'
    
    for i in range(2):
        tmp = []
        
        for j in range(i - 2, n, 2):
            tmp.append(s[fmax(j, 0):j + 2])
        
        tmp.sort()
        ans = min(ans, ''.join(x * k for x in tmp))
    
    print(ans)
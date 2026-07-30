# Submission link: https://codeforces.com/gym/106631/submission/384839510
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        s = I()
        
        flg = True
        for i in range(n - 1):
            if s[i] != s[0]:
                flg = False
        
        outs.append('Bob' if flg else 'Alice')
    
    print('\n'.join(outs))
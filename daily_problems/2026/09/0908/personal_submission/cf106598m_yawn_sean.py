# Submission link: https://codeforces.com/gym/106598/submission/389713738
def main():
    s1, s2 = LI()
    p, q = MII()
    
    if not p or not q: print('=')
    else:
        v1 = s1 + s2
        v2 = s2 + s1
        
        if v1 < v2: print('<')
        elif v1 > v2: print('>')
        else: print('=')
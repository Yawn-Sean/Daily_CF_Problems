# Submission link: https://codeforces.com/gym/105669/submission/347541868
def main(): 
    s1, op, s2 = LI()
    
    mod1 = 10 ** 9 + 7
    mod2 = 10 ** 9 + 6
    
    v1 = 0
    for c in s1:
        v1 = (10 * v1 + int(c)) % mod1
    
    v2 = 0
    for c in s2:
        v2 = (10 * v2 + int(c)) % (mod1 if op != '^' else mod2)
    
    if op == '+': print((v1 + v2) % mod1)
    elif op == '-': print((v1 - v2) % mod1)
    elif op == '*': print(v1 * v2 % mod1)
    else: print(pow(v1, v2, mod1))
# Submission link: https://codeforces.com/gym/105973/submission/347202302
def main(): 
    mod = 998244353
    
    M = 10 ** 6
    f = Factorial(M, mod)
    
    acc = [0] * (M + 1)
    for i in range(1, M + 1):
        acc[i] = acc[i - 1] ^ 1 ^ (0 if i % 2 else f.combi(i, i // 2))
    
    t = II()
    outs = []
    
    for _ in range(t):
        outs.append(acc[II()])
    
    print('\n'.join(map(str, outs)))
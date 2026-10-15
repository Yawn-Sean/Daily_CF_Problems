# Submission link: https://codeforces.com/gym/102829/submission/394636471
def main():
    mod = 10 ** 9 + 7
    f = Factorial(2 * 10 ** 6 + 5, mod)
    
    t = II()
    outs = []
    
    for _ in range(t):
        x, y = MII()
        x = abs(x) + 1
        y = abs(y) + 1
        outs.append(f.combi(x + y, x) - 1)
    
    print('\n'.join(map(str, outs)))
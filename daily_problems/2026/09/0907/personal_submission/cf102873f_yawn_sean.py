# Submission link: https://codeforces.com/gym/102873/submission/389665584
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        if n % 4 == 0: outs.append('Draw')
        elif n % 4 == 2: outs.append('Alice')
        else: outs.append('Bob')
    
    print('\n'.join(outs))
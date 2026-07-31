# Submission link: https://codeforces.com/gym/106631/submission/384941144
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        s = I()
        
        if s == '1' * n: outs.append('a' * n)
        elif s == ''.join('1' if i % 2 == 0 else '0' for i in range(n)):
            outs.append(''.join('a' if i % 2 == 0 else 'b' for i in range(n)))
        elif s == '1' + '0' * (n - 1):
            outs.append('a' * (n - 1) + 'b')
        elif n >= 2 and s == '1' + '0' * (n - 2) + '1':
            outs.append('a' * ((n - 1) // 2) + 'b' * (n - (n - 1) // 2 * 2) + 'a' * ((n - 1) // 2))
        else:
            outs.append('-1')
    
    print('\n'.join(outs))
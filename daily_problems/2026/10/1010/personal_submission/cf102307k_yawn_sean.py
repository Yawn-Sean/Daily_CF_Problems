# Submission link: https://codeforces.com/gym/102307/submission/393785065
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        outs.append(n - (n + 1) // 3 if n >= 3 else 0)
    
    print('\n'.join(map(str, outs)))
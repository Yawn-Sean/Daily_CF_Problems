# Submission link: https://codeforces.com/gym/104679/submission/342416060
def main():
    M = 10 ** 7
    is_prime = [1] * (M + 1)
    is_prime[0] = 0
    is_prime[1] = 0
    
    for i in range(2, M + 1):
        if is_prime[i]:
            for j in range(i * 2, M + 1, i):
                is_prime[j] = 0
    
    for i in range(1, M + 1):
        is_prime[i] += is_prime[i - 1]
    
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        if n <= 3: outs.append(n - 2)
        else: outs.append(is_prime[n] - is_prime[n // 2])
    
    print('\n'.join(map(str, outs)))
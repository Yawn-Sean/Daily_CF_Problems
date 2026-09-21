# Submission link: https://codeforces.com/gym/101055/submission/391376321
def main():
    M = 200000
    
    is_prime = [1] * M
    is_prime[0] = 0
    is_prime[1] = 0
    
    miu = [1] * M
    
    for i in range(M):
        if is_prime[i]:
            for j in range(i, M, i):
                is_prime[j] = 0
                miu[j] *= -1
                
                if j // i % i == 0:
                    miu[j] = 0
    
    chosen = [i for i in range(1, M) if miu[i]]
    
    t = II()
    outs = []
    
    for _ in range(t):
        x = II()
        
        l, r = 1, 4 * 10 ** 10
        while l <= r:
            mid = (l + r) // 2
            
            cnt = 0
            
            for i in chosen:
                cnt += miu[i] * (mid // i // i)
            
            if cnt >= x: r = mid - 1
            else: l = mid + 1
        
        outs.append(l)
    
    print('\n'.join(map(str, outs)))
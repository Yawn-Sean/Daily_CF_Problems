# Submission link: https://codeforces.com/gym/105757/submission/378045831
def main():
    M = 10 ** 6 + 10
    isPrime = [1] * M
    isPrime[0] = 0
    isPrime[1] = 0
    
    for i in range(2, M):
        if isPrime[i]:
            for j in range(2 * i, M, i):
                isPrime[j] = 0
    
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
    
        ans = [0] * n
        l, r = 0, n - 1
        
        while n:
            for x in range(1, n + 1):
                if isPrime[n + x]:
                    
                    for i in range(x, n + 1):
                        if i > n + x - i: break
                        ans[l] = i
                        ans[r] = n + x - i
                        l += 1
                        r -= 1
                    
                    n = x - 1
                    break
        
        outs.append(' '.join(map(str, ans)))
    
    print('\n'.join(outs))
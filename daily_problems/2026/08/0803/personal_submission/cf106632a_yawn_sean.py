# Submission link: https://codeforces.com/gym/106632/submission/385226554
def main():
    M = 10 ** 6 + 1
    isPrime = [1] * M
    cnt = [0] * M
    
    isPrime[0] = 0
    isPrime[1] = 0
    
    cnt[1] = 1
    
    for i in range(2, M):
        if isPrime[i]:
            for j in range(i * 2, M, i):
                isPrime[j] = 0
            
            v = i
            cur = 1
            
            while v < M:
                if cur & -cur == cur:
                    cnt[v] = 1
                v *= i
                cur += 1
    
    for i in range(1, M):
        cnt[i] += cnt[i - 1]
    
    t = II()
    outs = []
    
    for _ in range(t):
        outs.append(cnt[II()])
    
    print('\n'.join(map(str, outs)))
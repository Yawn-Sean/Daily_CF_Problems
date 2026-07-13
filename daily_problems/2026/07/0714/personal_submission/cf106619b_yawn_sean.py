# Submission link: https://codeforces.com/gym/106619/submission/382354970
def main():
    M = 2 * 10 ** 6 + 1
    pr = list(range(M))
    
    for i in range(2, M):
        if pr[i] == i:
            for j in range(i, M, i):
                pr[j] = i
    
    cnt = [0] * M
    
    for i in range(1, M):
        cur = i
        res = 1
    
        while cur > 1:
            p = pr[cur]
            c = 1
            
            while cur % p == 0:
                cur //= p
                c += 2
            
            res *= c
        
        cnt[i] = res // 2
    
    for i in range(1, M):
        cnt[i] += cnt[i - 1]
    
    t = II()
    outs = []
    
    for _ in range(t):
        outs.append(cnt[II()])
    
    print('\n'.join(map(str, outs)))
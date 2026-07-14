# Submission link: https://codeforces.com/gym/103306/submission/382489165
def main():
    M = 10 ** 6 + 5
    mod = 10 ** 9 + 7
    
    pr = list(range(M))
    phi = [1] * M
    
    phi[0] = 0
    
    for i in range(2, M):
        if pr[i] == i:
            for j in range(i, M, i):
                pr[j] = i
                if j % (i * i) == 0:
                    phi[j] = 0
                else:
                    phi[j] = -phi[j]
    
    cur = 1
    ans = [0] * M
    
    for i in range(1, M):
        cur = cur * 2 % mod
        
        for j in range(2 * i, M, i):
            ans[j] += (-phi[j // i]) * cur % mod
            ans[j] %= mod
    
    t = II()
    outs = []
    
    for _ in range(t):
        outs.append(ans[II()])
    
    print('\n'.join(map(str, outs)))
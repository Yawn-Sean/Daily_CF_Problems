# Submission link: https://codeforces.com/gym/103821/submission/381391007
def main():
    M = 10 ** 5 + 5
    cnt = [0] * M
    
    for i in range(1, M):
        for j in range(i * 2, M, i):
            cnt[j] += 1
    
    for i in range(1, M):
        cnt[i] += cnt[i - 1]
    
    outs = []
    mod = 10 ** 9 + 7
    rev2 = (mod + 1) // 2
    
    f = [1] * M
    
    for i in range(1, M):
        f[i] = i * f[i - 1] % mod
    
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        outs.append(cnt[n] * rev2 % mod * f[n] % mod)
    
    print('\n'.join(map(str, outs)))
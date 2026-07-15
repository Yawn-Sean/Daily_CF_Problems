'''
https://codeforces.com/gym/103306/submission/382736668
'''
def solve():
    MAXN = 10 ** 6 + 5
    MOD = 10 ** 9 + 7
    
    fa = list(range(MAXN))
    mu = [1] * MAXN
    mu[0] = 0
    
    for i in range(2, MAXN):
        if fa[i] == i:
            for j in range(i, MAXN, i):
                fa[j] = i
                if j % (i * i) == 0:
                    mu[j] = 0
                else:
                    mu[j] = -mu[j]
    
    po2 = 1
    ans = [0] * MAXN
    
    for i in range(1, MAXN):
        po2 = po2 * 2 % MOD
        for j in range(2 * i, MAXN, i):
            ans[j] = (ans[j] + (-mu[j // i]) * po2) % MOD
    
    return ans

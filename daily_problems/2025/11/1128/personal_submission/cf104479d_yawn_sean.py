# Submission link: https://codeforces.com/gym/104479/submission/350824367
def main(): 
    n, p, q = MII()
    mod = 998244353
    
    prob = p * pow(q, -1, mod) % mod
    
    dp = 1
    val = prob
    cur = 1
    
    for i in range(2, n + 1):
        dp = dp * cur % mod
        val = val * prob % mod
        cur = (cur * (1 - prob) + val) % mod
    
    print(dp)
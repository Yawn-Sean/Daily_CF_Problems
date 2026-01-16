# Submission link: https://codeforces.com/gym/104064/submission/358030273
def main(): 
    n, i, k = MII()
    ans = 0
    
    ans += ((i - 1) / n) ** k * i
    for M in range(i, n + 1):
        ans += ((M / n) ** k - ((M - 1) / n) ** k) * (M + 1) / 2
    
    print(ans)
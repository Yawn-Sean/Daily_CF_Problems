# Submission link: https://codeforces.com/contest/946/submission/283685442
def main():
    n, m, k = MII()
    dp = [0] * (k + 1)
    ans = 0

    for _ in range(n):
        s = I()
        idxs = [i for i in range(m) if s[i] == '1']
        l = len(idxs)
        
        if l > 0:
            saved = [0] * (l + 1)
            v = idxs[-1] - idxs[0] + 1
            
            ans += v
            saved[l] = v
            
            for i in range(l):
                for j in range(i, l):
                    saved[l - (j - i + 1)] = fmax(saved[l - (j - i + 1)], v - (idxs[j] - idxs[i] + 1))
            
            for i in range(k, 0, -1):
                for j in range(l + 1):
                    if i < j: break
                    dp[i] = fmax(dp[i], dp[i - j] + saved[j])

    print(ans - dp[k])
# Submission link: https://codeforces.com/contest/1176/submission/278704110
def main():
    n = II()

    inf = 10 ** 11
    dp = [-inf] * 10
    dp[0] = 0

    ndp = [-inf] * 10
    for _ in range(n):
        k = II()
        tmp = [[] for _ in range(4)]
        for i in range(k):
            c, d = MII()
            tmp[c].append(d)
        
        for i in range(1, 4):
            tmp[i] = nlargest(3 // i, tmp[i])
        

        for c1 in range(min(3, len(tmp[1])) + 1):
            for c2 in range(min((3 - c1) // 2, len(tmp[2])) + 1):
                for c3 in range(min((3 - c1 - c2 * 2) // 3, len(tmp[3])) + 1):
                    tot = 0
                    ma = 0
                    for i in range(c1):
                        tot += tmp[1][i]
                        ma = fmax(ma, tmp[1][i])
                    
                    for i in range(c2):
                        tot += tmp[2][i]
                        ma = fmax(ma, tmp[2][i])
                    
                    for i in range(c3):
                        tot += tmp[3][i]
                        ma = fmax(ma, tmp[3][i])

                    for i in range(10):
                        v = dp[i] + tot
                        ni = i + c1 + c2 + c3
                        if ni >= 10:
                            v += ma
                            ni -= 10
                        ndp[ni] = fmax(ndp[ni], v)

        for i in range(10):
            dp[i] = ndp[i]
            ndp[i] = -inf

    print(max(dp))
'''
https://codeforces.com/problemset/submission/73/321578376
'''
# (OTK) DP[k][c]: maximum possible euphony when changed k times and last character was c
def solve(s: str, k: int, n: int, a: list[tuple[str, str, int]]) -> int:
    mp = [[0] * 26 for _ in range(26)]
    for x, y, c in a:
        xi, yi = ord(x) - 97, ord(y) - 97
        mp[xi][yi] = c
    NS = -2147483648
    dp = [[NS] * 26 for _ in range(k + 1)]
    first = True
    for c in s:
        ci = ord(c) - 97
        dp1 = [[NS] * 26 for _ in range(k + 1)]
        if first:
            first = False
            dp1[0][ci] = 0
            if k:
                for j in range(26):
                    if j != ci:
                        dp1[1][j] = 0
        else:
            for d in range(k + 1):
                for i in range(26):
                    for j in range(26):
                        if dp[d][i] > NS:
                            if j == ci:
                                dp1[d][j] = max(dp1[d][j], dp[d][i] + mp[i][j])
                            elif d + 1 <= k:
                                dp1[d + 1][j] = max(dp1[d + 1][j], dp[d][i] + mp[i][j]) 
        dp = dp1
    return max(max(r) for r in dp)

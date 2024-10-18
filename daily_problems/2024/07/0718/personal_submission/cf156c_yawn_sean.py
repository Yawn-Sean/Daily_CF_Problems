# Submission Link: https://codeforces.com/contest/156/submission/271097891
def main():
    mod = 10 ** 9 + 7

    dp = [[0] * 2501 for _ in range(101)]
    dp[0][0] = 1

    dp_acc = [0] * 2502

    fmax = lambda x, y: x if x > y else y

    for i in range(1, 101):
        for j in range(2501):
            dp_acc[j+1] = dp_acc[j] + dp[i-1][j]
            if dp_acc[j+1] >= mod: dp_acc[j+1] -= mod
        
        for j in range(25 * i + 1):
            dp[i][j] = dp_acc[j+1] - dp_acc[fmax(j-25, 0)]
            if dp[i][j] < 0: dp[i][j] += mod

    t = II()
    outs = []

    for _ in range(t):
        s = I()
        l = len(s)
        x = sum(ord(c) - ord('a') for c in s)
        outs.append(dp[l][x] - 1 if dp[l][x] else mod - 1)

    print('\n'.join(map(str, outs)))
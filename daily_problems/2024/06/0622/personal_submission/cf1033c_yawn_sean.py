# Submission link: https://codeforces.com/contest/1033/submission/266775881
def main():
    n = II()
    perm = LGMI()

    pos = [0] * n
    for i in range(n):
        pos[perm[i]] = i

    dp = [0] * n

    for i in range(n - 1, -1, -1):
        for j in range(pos[i] % (i + 1), n, i + 1):
            if perm[j] > i and dp[j] == 0:
                dp[pos[i]] = 1
                break

    print(''.join('BA'[x] for x in dp))

# Submission link: https://codeforces.com/contest/615/submission/302302920
def main():
    s1 = [ord(c) for c in I()]
    s2 = [ord(c) for c in I()]

    n1 = len(s1)
    n2 = len(s2)

    ma_substr = [0] * n2
    idxs = [-1] * n2

    dp = [[0] * (n2 + 1) for _ in range(n1 + 1)]

    for i in range(n1 - 1, -1, -1):
        for j in range(n2 - 1, -1, -1):
            if s1[i] == s2[j]:
                dp[i][j] = dp[i + 1][j + 1] + 1
                if dp[i][j] > ma_substr[j]:
                    ma_substr[j] = dp[i][j]
                    idxs[j] = i

    for i in range(n1 + 1):
        for j in range(n2 + 1):
            dp[i][j] = 0

    s1 = s1[::-1]

    for i in range(n1 - 1, -1, -1):
        for j in range(n2 - 1, -1, -1):
            if s1[i] == s2[j]:
                dp[i][j] = dp[i + 1][j + 1] + 1
                if dp[i][j] > ma_substr[j]:
                    ma_substr[j] = dp[i][j]
                    idxs[j] = ~(n1 - 1 - i)

    pt = 0
    outs = []

    while pt < n2:
        if ma_substr[pt] == 0:
            exit(print(-1))
        if idxs[pt] >= 0:
            outs.append(f'{idxs[pt] + 1} {idxs[pt] + ma_substr[pt]}')
        else:
            outs.append(f'{~idxs[pt] + 1} {~idxs[pt] - ma_substr[pt] + 2}')
        pt += ma_substr[pt]

    print(len(outs))
    print('\n'.join(outs))
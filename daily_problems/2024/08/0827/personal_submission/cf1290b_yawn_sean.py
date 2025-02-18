# Submission link: https://codeforces.com/contest/1290/submission/278321952
def main():
    s = I()
    n = len(s)

    pref = [[0] * (n + 1) for _ in range(26)]

    for i in range(n):
        for j in range(26):
            pref[j][i+1] = pref[j][i]
        pref[ord(s[i]) - ord('a')][i+1] += 1

    q = II()
    outs = []

    for _ in range(q):
        l, r = GMI()
        c = 0
        for i in range(26):
            if pref[i][r+1] - pref[i][l]:
                c += 1
        outs.append('No' if l != r and c <= 2 and s[l] == s[r] else 'Yes')

    print('\n'.join(outs))
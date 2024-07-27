# Submission link: https://codeforces.com/contest/814/submission/272885210
def main():
    n = II()
    s = [ord(c) - ord('a') for c in I()]

    saved = [[0] * (n + 1) for _ in range(26)]
    fmax = lambda x, y: x if x > y else y

    for i in range(26):
        for j in range(1, n + 1):
            l, r = 0, 0
            cur = 0
            ans = 0
            while l < n:
                while r < n and cur + (s[r] != i) <= j:
                    cur += s[r] != i
                    r += 1
                ans = fmax(ans, r - l)
                cur -= s[l] != i
                l += 1
            saved[i][j] = ans

    q = II()
    outs = []

    for _ in range(q):
        m, c = LI()
        outs.append(saved[ord(c) - ord('a')][int(m)])

    print('\n'.join(map(str, outs)))
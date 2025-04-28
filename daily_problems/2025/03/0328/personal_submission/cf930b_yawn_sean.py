# Submission link: https://codeforces.com/problemset/submission/930/312729572#
def main():
    s = [ord(c) - ord('a') for c in I()]
    n = len(s)

    d = [[] for _ in range(26)]

    for i in range(n):
        d[s[i]].append(i)

    ans = 0
    for i in range(26):
        res = 0
        for p in range(n):
            cnt = [0] * 26
            for x in d[i]:
                cnt[s[(x + p) % n]] += 1
            res = fmax(res, sum(x == 1 for x in cnt))
        ans += res

    print(ans / n)
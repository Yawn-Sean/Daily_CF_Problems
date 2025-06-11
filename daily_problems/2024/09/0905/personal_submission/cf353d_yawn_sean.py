# Submission link: https://codeforces.com/contest/353/submission/279871887
def main():
    s = I()
    ans = 0
    cur = 0
    for c in s:
        if c == 'M':
            cur += 1
        elif cur > 0:
            ans = fmax(ans + 1, cur)

    print(ans)
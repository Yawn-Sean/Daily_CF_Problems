# Submission link: https://codeforces.com/contest/327/submission/319702676
def main():
    s = I()
    k = II()

    cur = 1
    ans = 0

    mod = 10 ** 9 + 7

    for i in range(len(s)):
        if s[i] == '0' or s[i] == '5':
            ans += cur
        
        cur += cur
        if cur >= mod:
            cur -= mod

    print(ans * (pow(2, len(s) * k, mod) - 1) % mod * pow(pow(2, len(s), mod) - 1, -1, mod) % mod)
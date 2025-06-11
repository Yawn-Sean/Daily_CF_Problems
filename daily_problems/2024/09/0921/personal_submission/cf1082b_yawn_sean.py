# Submission link: https://codeforces.com/contest/1082/submission/282141193
def main():
    n = II()
    s = I()

    ans = 0
    l = r = 0
    cnt = 0

    while l < n:
        while r < n and cnt + (s[r] == 'S') <= 1:
            cnt += s[r] == 'S'
            r += 1
        
        ans = fmax(ans, r - l)
        cnt -= s[l] == 'S'
        l += 1

    print(fmin(ans, s.count('G')))
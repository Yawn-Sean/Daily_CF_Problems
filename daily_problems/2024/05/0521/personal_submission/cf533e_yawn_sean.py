# Submission link: https://codeforces.com/contest/533/submission/261946810
def main():
    n = II()
    s1 = I()
    s2 = I()

    l = -1
    r = -1
    for i in range(n):
        if s1[i] != s2[i]:
            if l == -1: l = i
            r = i

    print((s1[l:r] == s2[l+1:r+1]) + (s1[l+1:r+1] == s2[l:r]))
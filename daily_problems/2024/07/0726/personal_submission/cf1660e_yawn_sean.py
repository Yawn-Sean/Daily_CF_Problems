# Submission link: https://codeforces.com/contest/1660/submission/272624505
def main():
    I()
    n = II()
    cnt = [0] * n
    for i in range(n):
        s = I()
        for j in range(n):
            if s[j] == '1':
                cnt[(i - j) % n] += 1
    return sum(cnt) + n - max(cnt) * 2
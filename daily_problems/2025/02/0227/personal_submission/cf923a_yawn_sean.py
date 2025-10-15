# Submission link: https://codeforces.com/contest/923/submission/308008510
def main():
    M = 10 ** 6
    prime_factor = list(range(M + 1))
    for i in range(2, M + 1):
        if prime_factor[i] == i:
            for j in range(i, M + 1, i):
                prime_factor[j] = i

    x2 = II()
    ans = x2

    for x1 in range(x2 - prime_factor[x2] + 1, x2 + 1):
        if prime_factor[x1] != x1:
            ans = fmin(ans, x1 - prime_factor[x1] + 1)

    print(ans)
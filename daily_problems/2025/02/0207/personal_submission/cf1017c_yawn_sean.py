# Submission link: https://codeforces.com/contest/1017/submission/304783735
def main():
    n = II()

    v = math.isqrt(n)
    ans = []

    for i in range(1, n // v + 2):
        for j in range(i * v, (i - 1) * v, -1):
            if 1 <= j <= n:
                ans.append(j)

    print(' '.join(map(str, ans)))
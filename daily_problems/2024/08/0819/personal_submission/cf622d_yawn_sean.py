# Submission link: https://codeforces.com/contest/622/submission/277113814
def main():
    n = II()
    ans = [0] * (n * 2)

    for i in range(n // 2):
        ans[i] = i * 2 + 1
        ans[n-i-1] = i * 2 + 1
        ans[n+i] = (i + 1) * 2
        ans[2*n-2-i] = (i + 1) * 2

    for i in range(n * 2):
        if ans[i] == 0:
            ans[i] = n

    print(' ' .join(map(str, ans)))
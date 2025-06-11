# Submission link: https://codeforces.com/contest/731/submission/282701030
def main():
    n = II()
    nums = LII()

    M = 2 * 10 ** 5
    acc = [0] * (M + 2)

    for x in nums:
        acc[x + 1] += 1

    for i in range(M + 1):
        acc[i + 1] += acc[i]

    ans = [0] * (M + 1)

    for i in range(1, M + 1):
        for j in range(0, M + 1, i):
            ans[i] += j * (acc[fmin(M + 1, j + i)] - acc[j])

    print(max(ans[x] for x in nums))
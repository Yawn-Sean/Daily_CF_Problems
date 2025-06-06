# Submission link: https://codeforces.com/contest/877/submission/318888330
def main():
    n = II()

    ans = []
    ans.extend(range(2, n + 1, 2))
    ans.extend(range(1, n + 1, 2))
    ans.extend(range(2, n + 1, 2))

    print(len(ans))
    print(*ans)
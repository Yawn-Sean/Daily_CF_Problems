# Submission link: https://codeforces.com/contest/553/submission/302156906
def main():
    n, k = MII()

    fib = [1, 1]
    while len(fib) < 53:
        fib.append(fib[-1] + fib[-2])

    k -= 1
    ans = []

    while len(ans) < n:
        l = len(ans)
        if k >= fib[n - l - 1]:
            ans.append(l + 2)
            ans.append(l + 1)
            k -= fib[n - l - 1]
        else:
            ans.append(l + 1)

    print(*ans)
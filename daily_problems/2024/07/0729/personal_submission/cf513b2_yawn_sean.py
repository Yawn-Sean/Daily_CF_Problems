# Submission link: https://codeforces.com/contest/513/submission/273255756
def main():
    n, k = MII()
    k -= 1

    ans = [0] * n
    l, r = 0, n - 1

    for i in range(1, n):
        if k >> (n - i - 1) & 1:
            ans[r] = i
            r -= 1
        else:
            ans[l] = i
            l += 1

    ans[l] = n
    print(*ans)
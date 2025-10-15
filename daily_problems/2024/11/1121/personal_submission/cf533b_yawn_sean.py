# Submission link: https://codeforces.com/contest/533/submission/292550209
def main():
    n = II()
    parent = [-1] * n
    values = [0] * n

    for i in range(n):
        parent[i], values[i] = MII()
        parent[i] -= 1

    dp0, dp1 = [0] * n, [-inf] * n

    for i in range(n - 1, 0, -1):
        p = parent[i]
        dp1[i] = fmax(dp1[i], dp0[i] + values[i])
        dp0[p], dp1[p] = fmax(dp0[p] + dp0[i], dp1[p] + dp1[i]), fmax(dp0[p] + dp1[i], dp1[p] + dp0[i])

    print(fmax(dp1[0], dp0[0] + values[0]))
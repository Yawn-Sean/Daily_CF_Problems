import sys

N = 2005
a = [0] * N
dp = [[0.0] * 10005 for _ in range(5)]
f = [0.0] * 10005

def main():
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    a = list(map(int, data[1:n+1]))

    mx = -1e9
    mi = 1e9

    tmp = 1.0 / (n * (n - 1) / 2)

    for i in range(1, n + 1):
        mx = max(mx, a[i-1])
        mi = min(mi, a[i-1])

    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if a[i-1] > a[j-1]:
                dp[1][a[i-1] - a[j-1]] += tmp
                dp[2][a[i-1] - a[j-1]] += tmp

    for i in range(1, mx - mi + 1):
        for j in range(1, mx - mi + 1):
            dp[3][i + j] += dp[1][i] * dp[2][j]

    for i in range(1, 2 * (mx - mi) + 1):
        f[i] = f[i-1] + dp[3][i]

    ans = 0.0
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if a[j-1] > a[i-1]:
                ans += f[a[j-1] - a[i-1] - 1] * tmp

    print(f"{ans:.10f}")

if __name__ == "__main__":
    main()

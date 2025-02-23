def main():
    s = input().split(" ")
    N, p, T = int(s[0]), float(s[1]), int(s[2])
    f = [[0 for j in range(N + 1)] for i in range(T + 1)]
    f[0][0] = 1
    for t in range(1, T + 1):
        f[t][0] = f[t - 1][0] * (1 - p)
        for i in range(1, min(t, N) + 1):
            f[t][i] = f[t - 1][i] * (1 - p) + f[t - 1][i - 1] * p
        f[t][N] += f[t - 1][N] * p
    ans = 0
    for i in range(N + 1):
        ans += f[t][i] * i
    print(ans)

if __name__ == '__main__':
    main()
f = [0] * 300005


def solve(mod):
    n, k = map(int, input().split())
    cnt = n
    for _ in range(k):
        a, b = map(int, input().split())
        if a != b:
            cnt = cnt - 2
        else:
            cnt = cnt - 1
    print(f[cnt])


if __name__ == "__main__":
    mod = 10**9 + 7
    f[1] = 1
    f[0] = 1
    for i in range(2, 300005, 1):
        f[i] = (f[i - 1] + 2 * (i - 1) * f[i - 2] % mod) % mod
    t = int(input())
    while t > 0:
        solve(mod)
        t -= 1

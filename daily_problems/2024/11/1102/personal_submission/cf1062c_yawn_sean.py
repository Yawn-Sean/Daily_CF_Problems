# Submission link: https://codeforces.com/contest/1062/submission/289334019
def main():
    n, q = MII()
    s = I()

    acc_1 = [0] * (n + 1)
    pow_2 = [1] * (n + 1)

    mod = 10 ** 9 + 7

    for i in range(n):
        acc_1[i + 1] = acc_1[i] + int(s[i])
        pow_2[i + 1] = pow_2[i] * 2 % mod

    outs = []
    for _ in range(q):
        l, r = MII()
        l -= 1
        outs.append((pow_2[r - l] - pow_2[r - l - (acc_1[r] - acc_1[l])]) % mod)

    print('\n'.join(map(str, outs)))
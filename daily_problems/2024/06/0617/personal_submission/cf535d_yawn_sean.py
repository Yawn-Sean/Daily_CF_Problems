# Submission link: https://codeforces.com/contest/535/submission/266124866
def z_algorithm(s):

    if isinstance(s, str):
        s = [ord(c) for c in s]

    n = len(s)
    if n == 0:
        return []

    z = [0] * n
    j = 0
    for i in range(1, n):
        z[i] = 0 if j + z[j] <= i else min(j + z[j] - i, z[i - j])
        while i + z[i] < n and s[z[i]] == s[i + z[i]]:
            z[i] += 1
        if j + z[j] < i + z[i]:
            j = i
    z[0] = n

    return z

def main():
    n, m = MII()
    s = I()
    pos = LGMI()

    k = len(s)
    z = z_algorithm(s)

    for i in range(m - 1):
        if pos[i + 1] - pos[i] >= k: continue
        j = pos[i + 1] - pos[i]
        if z[j] + j != k: exit(print(0))

    diff = [0] * (n + 1)
    for p in pos:
        diff[p] += 1
        diff[p+k] -= 1

    ans = 1
    mod = 10 ** 9 + 7

    for i in range(n):
        diff[i+1] += diff[i]
        if diff[i] == 0:
            ans *= 26
            ans %= mod

    print(ans)
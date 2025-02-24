# Submission link: https://codeforces.com/contest/1036/submission/307207204
def main():
    t = II()
    outs = []

    for _ in range(t):
        n, m, k = MII()
        if fmax(n, m) > k: outs.append(-1)
        elif (n + m) % 2: outs.append(k - 1)
        elif n % 2 == k % 2: outs.append(k)
        else: outs.append(k - 2)

    print('\n'.join(map(str, outs)))
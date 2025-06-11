# Submission link: https://codeforces.com/contest/1080/submission/320573711
def main():
    t = II()
    outs = []

    f = [0]

    for _ in range(31):
        f.append(4 * f[-1] + 1)

    for _ in range(t):
        n, k = MII()
        if n > 31: outs.append(f'YES {n - 1}')
        else:
            for i in range(n):
                cuts = n - i
                left = (1 << cuts + 1) - 2 - cuts
                right = f[n] - ((1 << cuts + 1) - 1) * f[i]
                if left <= k <= right:
                    outs.append(f'YES {i}')
                    break
            else:
                outs.append('NO')

    print('\n'.join(outs))
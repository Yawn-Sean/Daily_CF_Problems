# Submission link: https://codeforces.com/contest/1951/submission/312633113
def main():
    t = II()
    outs = []

    for _ in range(t):
        n, k = MII()
        
        if n == k:
            outs.append('YES')
            outs.append('1')
            outs.append('1')
        elif 2 * (n - k + 1) > n:
            outs.append('YES')
            outs.append('2')
            outs.append(f'{n - k + 1} 1')
        else:
            outs.append('NO')

    print('\n'.join(outs))
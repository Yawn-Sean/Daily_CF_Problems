# Submission link: https://codeforces.com/contest/1118/submission/286148192
def main():
    n, k = MII()
    if n > k * (k - 1):
        print('NO')
    else:
        print('YES')
        outs = []
        for i in range(1, k + 1):
            for j in range(1, i):
                outs.append(f'{j} {i}')
                outs.append(f'{i} {j}')
                if len(outs) >= n:
                    print('\n'.join(outs[:n]))
                    exit()
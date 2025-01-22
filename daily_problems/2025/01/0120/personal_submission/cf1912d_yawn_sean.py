# Submission link: https://codeforces.com/contest/1912/submission/301929337
def main():
    t = II()
    outs = []

    for _ in range(t):
        b, n = MII()
        cur = 1
        for i in range(1, n + 1):
            cur = cur * b % n
            if cur == 0:
                outs.append(f'1 {i}')
                break
            if cur == 1:
                outs.append(f'2 {i}')
                break
            if cur == n - 1:
                outs.append(f'3 {i}')
                break
        else:
            outs.append('0')

    print('\n'.join(outs))
# Submission link: https://codeforces.com/contest/492/submission/255554790
def main():
    n, x, y = MII()
    outs = []
    for _ in range(n):
        v = II()
        l, r = 1, 10 ** 15
        while l <= r:
            m = (l + r) // 2
            if m // x + m // y >= v:
                r = m - 1
            else:
                l = m + 1
        if l % x == 0:
            if l % y == 0:
                outs.append('Both')
            elif l % x == 0:
                outs.append('Vova')
        else:
            outs.append('Vanya')

    print('\n'.join(outs))
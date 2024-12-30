# Submission Link: https://codeforces.com/contest/792/submission/271998521
def main():
    orig, q = MII()

    outs = []
    for _ in range(q):
        n = II()
        s = I()
        
        for c in s:
            x = n & -n
            if c == 'L':
                if x > 1:
                    n -= x // 2
            elif c == 'R':
                if x > 1:
                    n += x // 2
            else:
                if x * 2 < orig:
                    n -= x
                    n |= x * 2
        outs.append(n)

    print('\n'.join(map(str, outs)))
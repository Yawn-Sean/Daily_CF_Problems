# Submission link: https://codeforces.com/contest/938/submission/298348038
def main():
    t = II()
    outs = []

    for _ in range(t):
        x = II()
        flg = False
        
        if x == 0: outs.append('1 1')
        else:
            for i in range(1, x):
                if i * i >= x: break
                if x % i == 0:
                    a, b = x // i, i
                    n = (a + b) // 2
                    m = (a + b) // (a - b)
                    if n * n - (n // m) * (n // m) == x:
                        outs.append(f'{n} {m}')
                        flg = True
                        break
            if not flg:
                outs.append('-1')

    print('\n'.join(outs))
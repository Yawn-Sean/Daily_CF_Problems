# Submission link: https://codeforces.com/contest/323/submission/298740674
def main():
    n = II()
    if n % 2: print(-1)
    else:
        outs = []
        for i in range(n):
            if i: outs.append('')
            for j in range(n):
                outs.append(''.join('wb'[(i & 1) ^ (j >> 1 & 1) ^ (k >> 1 & 1)] for k in range(n)))
        print('\n'.join(outs))
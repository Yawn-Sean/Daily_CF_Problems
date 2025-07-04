# Submission link: https://codeforces.com/contest/234/submission/327312481
def main():
    fin = open('input.txt', 'r')
    fout = open('output.txt', 'w')

    input = lambda: fin.readline().strip()

    def fprint(x):
        fout.write(str(x))
        fout.write('\n')

    n = II()
    k = (n - 1).bit_length()

    fprint(k)

    for i in range(k):
        tmp = [j for j in range(n) if j >> i & 1]
        fprint(f"{len(tmp)} {' '.join(map(str, tmp))}")
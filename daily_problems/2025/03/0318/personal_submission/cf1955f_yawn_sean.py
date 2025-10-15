# Submission link: https://codeforces.com/contest/1955/submission/311183831
def main():
    t = II()
    outs = []

    for _ in range(t):
        a, b, c, d = MII()
        outs.append(a // 2 + b // 2 + c // 2 + d // 2 + (a & b & c & 1))

    print('\n'.join(map(str, outs)))
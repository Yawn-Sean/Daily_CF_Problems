# Submission link: https://codeforces.com/gym/106682/submission/389362580
def main():
    n = II()
    d = {}

    for _ in range(n):
        a, c = MII()
        d[a] = c


    for x in sorted(d, reverse=True):
        if d[x]:
            v = (1 << x.bit_length()) - 1 - x
            if v not in d or d[v] < d[x]:
                exit(print('Ana'))
            d[v] -= d[x]

    print('Beto')
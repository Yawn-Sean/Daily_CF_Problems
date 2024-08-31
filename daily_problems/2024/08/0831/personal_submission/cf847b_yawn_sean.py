# Submission link: https://codeforces.com/contest/847/submission/278870381
def main():
    n = II()

    ars = []
    ma_val = []

    for num in MII():
        p = bisect.bisect_left(ma_val, -num)
        if p == len(ma_val):
            ars.append([-num])
            ma_val.append(-num)
        else:
            ars[p].append(-num)
            ma_val[p] = -num

    print('\n'.join(' '.join(str(-x) for x in ar) for ar in ars))
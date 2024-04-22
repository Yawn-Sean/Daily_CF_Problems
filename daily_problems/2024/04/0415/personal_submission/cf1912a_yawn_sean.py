# Submission link: https://codeforces.com/contest/1912/submission/256711994
def main():
    x, k = MII()
    ops = []

    for _ in range(k):
        n, *nums = MII()
        v = 0
        mi = 0
        ma = 0
        lma = ma
        for num in nums:
            v += num
            mi = min(mi, v)
            ma = max(ma, v)
            if ma > lma:
                ops.append((-mi, ma - lma))
                lma = ma

    ops.sort()
    for mi, ma in ops:
        if x < mi: break
        x += ma

    print(x)
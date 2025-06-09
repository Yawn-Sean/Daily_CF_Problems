# Submission link: https://codeforces.com/contest/617/submission/317888179
def main():
    xs = [0] * 3
    ys = [0] * 3

    for i in range(3):
        xs[i], ys[i] = MII()

    if xs[0] == xs[1] == xs[2] or ys[0] == ys[1] == ys[2]:
        print(1)
    else:
        for i in range(3):
            i1 = (i + 1) % 3
            i2 = (i + 2) % 3
            if xs[i1] == xs[i2] and not (fmin(ys[i1], ys[i2]) < ys[i] < fmax(ys[i1], ys[i2])):
                exit(print(2))
            if ys[i1] == ys[i2] and not (fmin(xs[i1], xs[i2]) < xs[i] < fmax(xs[i1], xs[i2])):
                exit(print(2))
        print(3)
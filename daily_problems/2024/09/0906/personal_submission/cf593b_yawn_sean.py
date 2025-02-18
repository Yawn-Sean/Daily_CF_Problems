# Submission link: https://codeforces.com/contest/593/submission/280002151
def main():
    n = II()
    x1, x2 = MII()

    tmp = []
    for _ in range(n):
        k, b = MII()
        tmp.append((k * x1 + b, k * x2 + b))

    tmp.sort()
    for i in range(1, n):
        if tmp[i][1] < tmp[i-1][1]:
            exit(print('YES'))
    print('NO')
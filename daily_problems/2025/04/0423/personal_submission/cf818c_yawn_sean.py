# Submission link: https://codeforces.com/contest/818/submission/316751716
def main():
    d = II()
    n, m = MII()

    cols_l = [0] * (n + 2)
    cols_r = [0] * (n + 2)

    rows_u = [0] * (m + 2)
    rows_d = [0] * (m + 2)

    x1s = []
    y1s = []
    x2s = []
    y2s = []

    for _ in range(d):
        x1, y1, x2, y2 = MII()
        if x1 > x2:
            x1, x2 = x2, x1
        if y1 > y2:
            y1, y2 = y2, y1
        x1s.append(x1)
        y1s.append(y1)
        x2s.append(x2)
        y2s.append(y2)
        
        cols_l[x1] += 1
        cols_r[x2] += 1
        
        rows_u[y1] += 1
        rows_d[y2] += 1

    for i in range(1, n + 1):
        cols_l[i] += cols_l[i - 1]

    for i in range(n, -1, -1):
        cols_r[i] += cols_r[i + 1]

    for i in range(1, m + 1):
        rows_u[i] += rows_u[i - 1]

    for i in range(m, -1, -1):
        rows_d[i] += rows_d[i + 1]

    cl, cr, cu, cd = MII()

    for i in range(d):
        vcl = cols_l[x2s[i] - 1]
        vcr = cols_r[x1s[i] + 1]
        vcu = rows_u[y2s[i] - 1]
        vcd = rows_d[y1s[i] + 1]
        
        if x1s[i] < x2s[i]:
            vcl -= 1
            vcr -= 1
        else:
            vcu -= 1
            vcd -= 1
        
        if cl == vcl and cr == vcr and cu == vcu and cd == vcd:
            print(i + 1)
            exit()

    print(-1)
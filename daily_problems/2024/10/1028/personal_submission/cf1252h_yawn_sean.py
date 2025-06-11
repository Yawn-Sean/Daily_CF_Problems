# Submission link: https://codeforces.com/contest/1252/submission/288403029
def main():
    n = II()
    ws = []
    ls = []

    ans = 0
    for _ in range(n):
        w, l = MII()
        if w > l:
            w, l = l, w
        ws.append(w)
        ls.append(l)
        ans = fmax(ans, w * l)

    ma_l = 0
    for i in sorted(range(n), key=lambda x: -ws[x]):
        ans = fmax(ans, 2 * ws[i] * fmin(ls[i], ma_l))
        ma_l = fmax(ma_l, ls[i])

    print(f'{ans // 2}.{ans % 2 * 5}')
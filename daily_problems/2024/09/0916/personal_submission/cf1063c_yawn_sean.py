# Submission link: https://codeforces.com/contest/1063/submission/281422200
def main():
    def query(x, y):
        print(x, y, flush=True)
        return I()[0] == 'b'

    n = II()

    l, r = 0, 10 ** 9
    flg = query(r, r)

    for _ in range(n - 1):
        m = (l + r) // 2
        if query(m, m) == flg: r = m
        else: l = m

    print(l, r, r, l)
# Submission link: https://codeforces.com/contest/1019/submission/278451864
def main():
    def query(x):
        print('?', x, flush=True)
        v1 = II()
        print('?', x + n // 2, flush=True)
        v2 = II()
        return v1 - v2

    def answer(x):
        print('!', x)

    n = II()
    if n % 4 == 2:
        answer(-1)
    else:
        l, r = 1, n // 2
        target = query(1)
        if target == 0:
            answer(1)
        else:
            sign = 1 if target > 0 else -1
            while l <= r:
                m = (l + r) // 2
                v = query(m)
                if v == 0:
                    answer(m)
                    exit()
                if v * sign > 0: l = m + 1
                else: r = m - 1
            answer(l)
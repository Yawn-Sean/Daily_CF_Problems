# Submission link: https://codeforces.com/contest/809/submission/285395732
def main():
    def query(x, y):
        print(1, x, y, flush=True)
        return True if I()[0] == 'T' else False

    def search(l, r):
        while l < r:
            m = (l + r) // 2
            if query(m, m + 1): r = m
            else: l = m + 1
        return r

    def answer(x, y):
        print(2, x, y)

    n, k = MII()
    x = search(1, n)
    y = search(1, x - 1)
    if y == 0 or not query(y, x): y = search(x + 1, n)
    answer(x, y)
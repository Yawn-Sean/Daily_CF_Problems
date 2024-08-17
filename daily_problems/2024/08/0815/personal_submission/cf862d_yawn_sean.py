# Submission link: https://codeforces.com/contest/862/submission/276462926
def main():
    def query(s):
        print('?', ''.join(map(str, s)), flush=True)
        return II()

    def answer(pos0, pos1):
        print('!', pos0 + 1, pos1 + 1)

    n = II()

    pos0 = pos1 = -1
    s = [0] * n
    x = query(s)
    s[n - 1] = 1
    y = query(s)

    if x < y:
        pos0 = n - 1
        benchmark = query([1] * n)
        l, r = 0, n - 2
        while l <= r:
            mid = (l + r) // 2
            if benchmark - query([0] * (mid + 1) + [1] * (n - mid - 1)) == mid + 1:
                l = mid + 1
            else:
                r = mid - 1
        pos1 = l
    else:
        pos1 = n - 1
        benchmark = x
        l, r = 0, n - 2
        while l <= r:
            mid = (l + r) // 2
            if benchmark - query([1] * (mid + 1) + [0] * (n - mid - 1)) == mid + 1:
                l = mid + 1
            else:
                r = mid - 1
        pos0 = l

    answer(pos0, pos1)
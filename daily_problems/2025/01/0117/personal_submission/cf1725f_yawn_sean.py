# Submission link: https://codeforces.com/contest/1725/submission/301311788
def main():
    n = II()
    ls = []
    rs = []

    rnd = random.getrandbits(20)

    for _ in range(n):
        l, r = MII()
        ls.append(l + rnd)
        rs.append(r + rnd)

    ans = [-1] * 30

    for i in range(30):
        lazy = 0
        prs = []
        
        length = 1 << i
        for j in range(n):
            l = ls[j]
            r = rs[j]
            if r - l + 1 >= length:
                lazy += 1
            else:
                l %= length
                r %= length
                prs.append(l * 2 + 1)
                prs.append((r + 1) * 2)
                if l > r:
                    lazy += 1
        
        lazy -= 1
        prs.append(1)
        
        cur = lazy
        for v in sorted(prs):
            a, b = divmod(v, 2)
            if a == length: break
            cur += 1 if b else -1
            ans[i] = fmax(ans[i], cur)

    q = II()
    outs = []

    for _ in range(q):
        v = II()
        outs.append(ans[(v & -v).bit_length() - 1])

    print('\n'.join(map(str, outs)))
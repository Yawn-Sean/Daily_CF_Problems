# Submission link: https://codeforces.com/contest/1147/submission/278184985
def main():
    n, m = MII()
    ls = []
    rs = []
    vis = set()

    for _ in range(m):
        l, r = GMI()
        if l > r: l, r = r, l
        ls.append(l)
        rs.append(r)
        vis.add((l, r))

    tmp = n
    for i in range(2, n + 1):
        if n % i == 0:
            while n % i == 0:
                n //= i
            x = tmp // i
            flg = True
            for i in range(m):
                nl = (ls[i] + x) % tmp
                nr = (rs[i] + x) % tmp
                if nl > nr: nl, nr = nr, nl
                if (nl, nr) not in vis:
                    flg = False
                    break
            if flg:
                print('Yes')
                exit()
    print('No')
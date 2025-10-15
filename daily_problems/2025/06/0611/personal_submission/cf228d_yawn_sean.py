# Submission link: https://codeforces.com/contest/228/submission/323834041
def main():
    n = II()
    nums = LII()

    q = II()
    ts = []
    xs = []
    ys = []
    zs = []

    for _ in range(q):
        query = LII()
        if query[0] == 1:
            ts.append(0)
            xs.append(query[1] - 1)
            ys.append(query[2])
            zs.append(0)
        else:
            ts.append(1)
            xs.append(query[1] - 1)
            ys.append(query[2] - 1)
            zs.append(query[3])

    fen = FenwickTree(n)
    tmp = [0] * n

    ans = [-1] * q

    for i in range(2, 7):
        weight = [0] * (2 * i - 2)
        for j in range(i - 1):
            weight[j] = j + 1
        for j in range(i - 1, 2 * i - 2):
            weight[j] = 2 * i - j - 1
        l = 2 * i - 2
        
        for start in range(l):
            for j in range(n):
                tmp[j] = nums[j] * weight[(j - start) % l]
            fen.init(tmp)
            
            for j in range(q):
                if ts[j] == 0:
                    fen.add(xs[j], ys[j] * weight[(xs[j] - start) % l] - tmp[xs[j]])
                    tmp[xs[j]] = ys[j] * weight[(xs[j] - start) % l]
                elif xs[j] % l == start and zs[j] == i:
                    ans[j] = fen.rsum(xs[j], ys[j])

    print('\n'.join(str(x) for x in ans if x != -1))
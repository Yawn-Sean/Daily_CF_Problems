# Submission link: https://codeforces.com/contest/1090/submission/275873561
def main():
    n, m = MII()

    vis = set()
    rnd = random.getrandbits(26)

    for _ in range(m):
        u, v = GMI()
        vis.add(u * rnd + v)
        vis.add(v * rnd + u)

    if m == n * (n - 1) // 2:
        print('NO')
    else:
        flg = False
        for i in range(n):
            for j in range(i):
                if i * rnd + j not in vis:
                    x, y = i, j
                    flg = True
                    if flg: break
            if flg: break
        ans = [0] * n
        ans[x] = 1
        ans[y] = 2
        cur = 3
        for i in range(n):
            if ans[i] == 0:
                ans[i] = cur
                cur += 1
        print('YES')
        print(' '.join(map(str, ans)))
        ans[y] = 1
        print(' '.join(map(str, ans)))
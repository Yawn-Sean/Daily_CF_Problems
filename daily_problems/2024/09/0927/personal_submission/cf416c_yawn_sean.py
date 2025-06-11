# Submission link: https://codeforces.com/contest/416/submission/283112076
def main():
    n = II()
    cs = []
    ps = []

    for _ in range(n):
        c, p = MII()
        cs.append(c)
        ps.append(p)

    k = II()
    rs = LII()

    st_n = sorted(range(n), key=lambda x: cs[x])
    st_k = sorted(range(k), key=lambda x: rs[x])

    pt = 0
    hpq = []

    ans = [-1] * n

    for i in st_k:
        while pt < n and cs[st_n[pt]] <= rs[i]:
            heappush(hpq, -ps[st_n[pt]] * n + st_n[pt])
            pt += 1
        
        if hpq:
            ans[heappop(hpq) % n] = i

    cnt = 0
    tot = 0
    outs = []

    for i in range(n):
        if ans[i] != -1:
            cnt += 1
            tot += ps[i]
            outs.append(f'{i + 1} {ans[i] + 1}')

    print(cnt, tot)
    print('\n'.join(outs))
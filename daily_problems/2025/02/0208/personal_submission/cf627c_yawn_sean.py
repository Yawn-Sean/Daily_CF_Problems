# Submission link: https://codeforces.com/contest/627/submission/304917134
def main():
    d, n, m = MII()

    xs = [0]
    ps = [0]

    for _ in range(m):
        x, p = MII()
        xs.append(x)
        ps.append(p)

    xs.append(d)
    ps.append(-1)

    st_range = sorted(range(m + 2), key=lambda x: xs[x])

    choice = [-1] * (m + 2)

    stk = [m + 1]
    for i in range(m, -1, -1):
        while ps[st_range[stk[-1]]] > ps[st_range[i]]:
            stk.pop()
        choice[i] = stk[-1]
        stk.append(i)

    ans = 0
    cur = n

    for i in range(m + 1):
        d = fmax(0, fmin(n, xs[st_range[choice[i]]] - xs[st_range[i]]) - cur)
        ans += d * ps[st_range[i]]
        cur += d - (xs[st_range[i + 1]] - xs[st_range[i]])
        if cur < 0: exit(print(-1))

    print(ans)
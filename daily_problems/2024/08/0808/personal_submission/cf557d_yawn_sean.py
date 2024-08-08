# Submission link: https://codeforces.com/contest/557/submission/275155267
def main():
    n, m = MII()

    if m == 0:
        print(3, math.comb(n, 3))
        exit()

    path = [[] for _ in range(n)]

    for _ in range(m):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)

    cols = [-1] * n
    ans1 = 0
    for i in range(n):
        if cols[i] == -1:
            cols[i] = 0
            stk = [i]
            c0, c1 = 1, 0
            while stk:
                u = stk.pop()
                for v in path[u]:
                    if cols[v] == -1:
                        cols[v] = cols[u] ^ 1
                        if cols[v]: c1 += 1
                        else: c0 += 1
                        stk.append(v)
                    elif cols[u] == cols[v]:
                        print(0, 1)
                        exit()
            ans1 += math.comb(c0, 2) + math.comb(c1, 2)

    if ans1: print(1, ans1)
    else: print(2, m * (n - 2))
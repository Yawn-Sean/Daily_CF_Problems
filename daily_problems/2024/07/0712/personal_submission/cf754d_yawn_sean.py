# Submission Link: https://codeforces.com/contest/754/submission/270093990
def main():
    n, k = MII()
    ls = []
    rs = []

    for _ in range(n):
        l, r = MII()
        ls.append(l)
        rs.append(r)

    ans, chosen_l = -1, -1
    hpq = []

    for i in sorted(range(n), key=lambda x: ls[x]):
        heappush(hpq, rs[i])
        if len(hpq) > k: heappop(hpq)
        if len(hpq) == k:
            if hpq[0] - ls[i] > ans:
                ans = hpq[0] - ls[i]
                chosen_l = ls[i]

    if ans == -1:
        print(0)
        print(' '.join(map(str, range(1, k + 1))))
    else:
        chosen = []
        for i in range(n):
            if len(chosen) < k and ls[i] <= chosen_l and rs[i] >= chosen_l + ans:
                chosen.append(i + 1)
        print(ans + 1)
        print(' '.join(map(str, chosen)))
# Submission link: https://codeforces.com/contest/1044/submission/302301887
def main():
    n, m = MII()
    verti = [II() for _ in range(n)]
    hori = []

    for _ in range(m):
        x1, x2, y = MII()
        if x1 == 1:
            hori.append(x2)

    verti.sort()
    hori.sort()

    verti.append(10 ** 9)

    ans = n + m
    pt = len(hori) - 1

    for i in range(n, -1, -1):
        while pt >= 0 and hori[pt] >= verti[i]:
            pt -= 1
        ans = fmin(ans, i + len(hori) - pt - 1)

    print(ans)